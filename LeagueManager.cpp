#include <LeagueManager.h>
#include <DataReader.h>
#include <Logger.h>

#include <iostream>

#define ADD 1
#define REMOVE 0

#define FIRST_FIT_MODE 1
#define BEST_FIT_MODE 0

LeagueManager::LeagueManager() {
    writer = new DataWriter();
}

void LeagueManager::readData(std::string path) {
    try {
        reader = new DataReader(path);
        league = reader->readLeague();

        switch (league->getMode()) {
        case FIRST_FIT_MODE:
            Logger::logStr += "First fit mode\n";
            break;
        case BEST_FIT_MODE:
            Logger::logStr += "Best fit mode\n";
            break;
        }
        writer->setLeague(this->league);

        Season aSeason;
        league->addSeason(aSeason);
        for (int idxSeason = 0; idxSeason < league->getSeasonNum() - 1; idxSeason++) {
            readSeason(idxSeason);
            //clone current season
            league->addSeason(Season::clone(league->getSeason(idxSeason), league->getMode()));

            writePlayer2File(idxSeason);
        }

        readSeason(league->getSeasonNum() - 1);
        writePlayer2File(league->getSeasonNum() - 1);

        reader->closeStream();

    } catch (int ex) {
        throw Logger::QUIT_NEEDED_SIGNAL;
    } catch (std::out_of_range& ofr) {
        throw Logger::QUIT_NEEDED_SIGNAL;
    } catch (std::invalid_argument& ia) {
        Logger::logStr += Logger::WRONG_RECORD_MODE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }
}

void LeagueManager::readSeason(int idxSeason) {
    try {
        SeasonChangeWrapper* seasonChange = reader->readSeasonChange();
        readClub(seasonChange->getClubChange(), idxSeason);
        readPlayer(seasonChange->getPlayerChange(), idxSeason);
    } catch (int ex) {
        throw Logger::QUIT_NEEDED_SIGNAL;
    } catch (std::invalid_argument& ia) {
        throw Logger::QUIT_NEEDED_SIGNAL;
    } catch (std::out_of_range& ofr) {
        throw Logger::QUIT_NEEDED_SIGNAL;
    }
}

void LeagueManager::readClub(int clubChangeNum, int idxSeason) {
    try {
        for (int idxClub = 0; idxClub < clubChangeNum; idxClub++) {
            ClubChangeWrapper* clubChange = reader->readClub();
            ClubRecord aClub(clubChange->getName(), league->getMode());
            switch (clubChange->getMode()) {
            case ADD:
                if (league->getSeason(idxSeason).getClubManager()->addClub(aClub)) {
                    Logger::logStr += "Add club successfully\n";
                }
                else
                    Logger::logStr += "Add club failed\n";
                break;
            case REMOVE:
                if (league->getSeason(idxSeason).getClubManager()->removeClub(aClub)) {
                    Logger::logStr += "Remove club successfully\n";
                }
                else
                    Logger::logStr += "Remove club failed\n";
                break;
            default:
                break;
            }
        }
    } catch (int ex) {
        throw Logger::QUIT_NEEDED_SIGNAL;
    }
}

void LeagueManager::readPlayer(int playerChangeNum, int idxSeason) {
    try {
        for (int idxPlayer = 0; idxPlayer < playerChangeNum; idxPlayer++) {
            PlayerChangeWrapper* playerChange = reader->readPlayer();
            ClubRecord aClub(playerChange->getClubName());
            if (league->getSeason(idxSeason).getClubManager()->isClubExist(aClub)) {
                PlayerRecord aPlayer(playerChange->getPlayerName());
                switch (playerChange->getMode()) {
                case ADD:
                    if (league->getSeason(idxSeason).getClubManager()->getClub(aClub)
                            .getPlayerManager()->addPlayer(aPlayer)) {
                        Logger::logStr += "Add player successfully\n";
                    }
                    else
                        Logger::logStr += "Add player failed\n";
                    break;
                case REMOVE:
                    if (league->getSeason(idxSeason).getClubManager()->getClub(aClub)
                            .getPlayerManager()->removePlayer(aPlayer)) {
                        Logger::logStr += "Remove player successfully\n";
                    }
                    else
                        Logger::logStr += "Remove player failed\n";
                    break;
                default:
                    break;
                }
            }
        }
    } catch (int ex) {
        throw Logger::QUIT_NEEDED_SIGNAL;
    }
}

void LeagueManager::writeClub2File() {
    league->getSeason(league->getSeasonNum() - 1).getClubManager()->defragment();
    writer->writeClub2File();
}

void LeagueManager::writePlayer2File(int idxSeason) {
    std::list<ClubRecord> clubList = league->getSeason(idxSeason).getClubManager()->getClubsList();
    for (std::list<ClubRecord>::iterator iteClub = clubList.begin(); iteClub != clubList.end(); iteClub++) {
        ClubRecord aClub = *iteClub;
        if (aClub.getPlayerManager() == NULL)
            continue;
        aClub.getPlayerManager()->defragment();
        writer->writePlayer2File(aClub, idxSeason);
    }
}

void LeagueManager::writePlayer2File() {
    std::list<ClubRecord> clubList = league->getSeason(league->getSeasonNum() - 1)
            .getClubManager()->getClubsList();
    for (std::list<ClubRecord>::iterator iteClub = clubList.begin(); iteClub != clubList.end(); iteClub++) {
        ClubRecord aClub = *iteClub;
        aClub.getPlayerManager()->defragment();
        writer->writePlayer2File(aClub);
    }
}

void LeagueManager::setOutputPath(std::string path) {
    writer->setWritePath(path);
}

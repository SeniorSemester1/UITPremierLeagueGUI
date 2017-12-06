#include <Logger.h>
#include <DataReader.h>
#include <iostream>


DataReader::DataReader(std::string path)
{
    this->readStrm.open(path, std::ios::in);
}

League* DataReader::readLeague() {
    std::string seasonStr, modeStr;
    std::getline(readStrm, seasonStr, ' ');
    std::getline(readStrm, modeStr, '\n');

    Logger::logStr += seasonStr + " " + modeStr + "\n";

    int seasonInt = std::stoi(seasonStr);
    int modeInt = std::stoi(modeStr);

    if (modeInt != 0 && modeInt != 1) {
        Logger::logStr += Logger::WRONG_RECORD_MODE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    League* league = new League(seasonInt, modeInt);
    return league;
}

SeasonChangeWrapper* DataReader::readSeasonChange() {
    std::string clubChangeStr, playerChangeStr;
    std::getline(readStrm, clubChangeStr, ' ');
    std::getline(readStrm, playerChangeStr, '\n');

    Logger::logStr += clubChangeStr + " " + playerChangeStr + "\n";

    int clubChangeInt, playerChangeInt;
    try {
        clubChangeInt = std::stoi(clubChangeStr);

    } catch (std::invalid_argument ia) {
        Logger::logStr += Logger::WRONG_CLUB_CHANGE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    try {
        playerChangeInt = std::stoi(playerChangeStr);
    } catch (std::invalid_argument ia) {
        Logger::logStr += Logger::WRONG_PLAYER_CHANGE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    if (clubChangeInt < 0) {
        Logger::logStr += Logger::WRONG_CLUB_CHANGE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    if (playerChangeInt < 0) {
        Logger::logStr += Logger::WRONG_PLAYER_CHANGE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    SeasonChangeWrapper* seasonChange = new SeasonChangeWrapper(clubChangeInt, playerChangeInt);
    return seasonChange;
}

ClubChangeWrapper* DataReader::readClub()
{
    std::string modeStr, name;
    std::getline(readStrm, modeStr, ' ');
    std::getline(readStrm, name, '\n');

    Logger::logStr += modeStr + " " + name + "\n";

    int modeInt = std::stoi(modeStr);

    if (modeInt != 0 && modeInt != 1) {
        Logger::logStr += Logger::WRONG_DML_MODE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    if (name.size() > 3) {
        Logger::logStr += Logger::CLUB_SIZE_TOO_LONG_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }
    if (name.size() < 3) {
        Logger::logStr += Logger::CLUB_SIZE_TOO_SHORT_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    ClubChangeWrapper* wrapper = new ClubChangeWrapper(modeInt, name);
    return wrapper;
}

PlayerChangeWrapper* DataReader::readPlayer() {
    std::string modeStr, playerName, clubName;
    std::getline(readStrm, modeStr, ' ');
    std::getline(readStrm, clubName, ' ');
    std::getline(readStrm, playerName, '\n');

    Logger::logStr += modeStr + " " + clubName + " " + playerName + "\n";

    int modeInt = std::stoi(modeStr);

    if (modeInt != 0 && modeInt != 1) {
        Logger::logStr += Logger::WRONG_DML_MODE_MSG;
        throw Logger::QUIT_NEEDED_SIGNAL;
    }

    PlayerChangeWrapper* wrapper = new PlayerChangeWrapper(modeInt, playerName, clubName);
    return wrapper;
}

void DataReader::closeStream() {
    readStrm.close();
}



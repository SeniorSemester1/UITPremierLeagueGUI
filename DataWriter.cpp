#include "DataWriter.h"
#include <fstream>

DataWriter::DataWriter()
{
    writePath = "";
}

void DataWriter::writeClub2File() {
    std::fstream writeStrm;
    writeStrm.open(this->writePath + "CLUBS.TXT", std::ios::out);
    writeStrm << league->getSeason(league->getSeasonNum() - 1).getClubManager()->writeToString();
    writeStrm.close();
}

void DataWriter::writePlayer2File(ClubRecord club) {
    std::fstream writeStrm;
    writeStrm.open(this->writePath + club.getName() + ".TXT", std::ios::out);
    writeStrm << league->getSeason(league->getSeasonNum() - 1).getClubManager()->getClub(club)
                 .getPlayerManager()->writeToString();
    writeStrm.close();
}

void DataWriter::writePlayer2File(ClubRecord club, int idxSeason) {
    std::fstream writeStrm;
    writeStrm.open(this->writePath + club.getName() + "." + std::to_string(idxSeason + 1),
                   std::ios::out);
    writeStrm << league->getSeason(idxSeason).getClubManager()->getClub(club)
                 .getPlayerManager()->writeToString();
    writeStrm.close();
}

void DataWriter::setWritePath(std::string path) {
    this->writePath = path;
}

void DataWriter::setLeague(League* league) {
    this->league = league;
}

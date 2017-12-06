#include "DataWriter.h"
#include <fstream>

DataWriter::DataWriter(League* league)
{
    this->league = &*league;
}

void DataWriter::writeClub2File(std::string path) {
    std::fstream writeStrm;
    writeStrm.open(path, std::ios::out);
    writeStrm << league->getSeason(league->getSeasonNum() - 1).getClubManager()->writeToString();
    writeStrm.close();
}

void DataWriter::writePlayer2File(ClubRecord club) {
    std::fstream writeStrm;
    writeStrm.open(club.getName() + ".TXT", std::ios::out);
    writeStrm << league->getSeason(league->getSeasonNum() - 1).getClubManager()->getClub(club)
                 .getPlayerManager()->writeToString();
    writeStrm.close();
}

void DataWriter::writePlayer2File(ClubRecord club, int idxSeason) {
    std::fstream writeStrm;
    writeStrm.open(club.getName() + "." + std::to_string(idxSeason + 1), std::ios::out);
    writeStrm << league->getSeason(idxSeason).getClubManager()->getClub(club)
                 .getPlayerManager()->writeToString();
    writeStrm.close();
}

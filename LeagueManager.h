#ifndef LEAGUEMANAGER_H
#define LEAGUEMANAGER_H
#include <string>
#include <fstream>
#include <ClubRecord.h>
#include <PlayerRecord.h>
#include <League.h>
#include <DataReader.h>
#include <DataWriter.h>

class LeagueManager {
private:
    League* league;
    DataReader* reader;
    DataWriter* writer;
    void readSeason(int );
    void readClub(int, int );
    void readPlayer(int, int );
public:
    LeagueManager();
    void readData(std::string path);

    void writeClub2File();
    void writePlayer2File();
    void writePlayer2File(int );

    League* getLeague() { return league; }
    void setOutputPath(std::string path);
};

#endif // LEAGUEMANAGER_H

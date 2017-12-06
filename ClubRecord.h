#ifndef CLUB_H
#define CLUB_H
#include <string>
#include <fstream>
#include <list>

#include <PlayerRecord.h>
#include <PlayerManager.h>

class ClubRecord
{
private:
    std::string name;
    int RRN;
    int nextAvalRecord;
    PlayerManager* playerManager;
public:
    ClubRecord();
    ClubRecord(std::string );
    ClubRecord(std::string, int );

    std::string getName() {return name;}
    int getRRN() {return RRN;}
    int getNextAvailRecord() { return nextAvalRecord; }
    PlayerManager* getPlayerManager() {return playerManager;}

    void setName(std::string );
    void setRRN(int RRN);
    void setNextAvailRecord(int );
    void setPlayerManager(PlayerManager* );

    ClubRecord& operator =(const ClubRecord &);
    bool operator ==(ClubRecord );
    bool operator !=(ClubRecord );
    static ClubRecord& clone(ClubRecord, int recordMode);
};

#endif // CLUB_H

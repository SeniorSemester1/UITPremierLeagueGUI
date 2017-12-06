#ifndef CLUBMANAGER_H
#define CLUBMANAGER_H
#include <list>
#include <ClubRecord.h>

class ClubManager
{
private:
    int headNum;
    std::list<ClubRecord> clubsJoined;
    std::list<ClubRecord> clubsLeft;
    bool isInClubLeft(ClubRecord );
    ClubRecord getClubsLeft(ClubRecord );
public:
    ClubManager();

    static ClubManager& clone(ClubManager, int);

    std::list<ClubRecord> getClubsList() { return clubsJoined; }
    ClubRecord getClub(ClubRecord );
    int getHeadNum() {return headNum;}
    void setHeadNum(int );

    std::string writeToString();

    bool isClubExist(ClubRecord );
    bool addClub(ClubRecord );
    bool removeClub(ClubRecord );
    void defragment();

    ClubManager& operator =(const ClubManager &);
};

#endif // CLUBMANAGER_H

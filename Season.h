#ifndef SEASON_H
#define SEASON_H
#include <ClubManager.h>

class Season
{
private:
    ClubManager* clubManager;
public:
    Season();

    ClubManager* getClubManager() { return clubManager; }
    void setClubManager(ClubManager &);

    Season& operator =(const Season & );
    static Season& clone(Season, int);
};

#endif // SEASON_H

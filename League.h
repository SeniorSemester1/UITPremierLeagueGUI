#ifndef LEAGUE_H
#define LEAGUE_H
#include <Season.h>
#include <vector>


class League
{
private:
    int seasonNum;
    int mode;
    std::vector<Season> seasons;

public:
    League(int , int );
    int getSeasonNum() {return seasonNum;}
    int getMode() {return mode;}
    Season getSeason(int );
    void addSeason(Season );

};

#endif // LEAGUE_H

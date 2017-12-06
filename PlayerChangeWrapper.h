#ifndef PLAYERCHANGEWRAPPER_H
#define PLAYERCHANGEWRAPPER_H
#include <string>
#include <ClubRecord.h>

class PlayerChangeWrapper
{
private:
    int mode;
    std::string playerName;
    std::string clubName;
public:
    PlayerChangeWrapper(int, std::string, std::string);
    int getMode() {return mode;}
    std::string getPlayerName() {return playerName;}
    std::string getClubName() {return clubName;}
};

#endif // PLAYERCHANGEWRAPPER_H

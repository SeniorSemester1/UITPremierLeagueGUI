#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <list>
#include <PlayerRecord.h>


class PlayerManager
{
protected:
    int headNum;
    std::list<PlayerRecord> playersJoined;

    const int BYTE_OF_PLAYER_SIZE = 1;
    const int BYTE_OF_HEADER_AND_SPACE = 2;
    const int NONE_OF_NEXT_RECORD_AVAILABLE = -1;

    std::list<PlayerRecord>::iterator getNextAvailRecordByPosition(int );
public:

    std::list<PlayerRecord> getPlayersList() const { return playersJoined; }
    bool isPlayerExist(PlayerRecord );
    PlayerRecord getPlayer(PlayerRecord ) const;

    int getHeader() const {return headNum;}
    void setHeader(int );

    std::string writeToString();

    virtual bool addPlayer(PlayerRecord ) = 0;
    bool removePlayer(PlayerRecord );
    void defragment();

    PlayerManager& operator=(const PlayerManager &);

};

#endif // PLAYERMANAGER_H

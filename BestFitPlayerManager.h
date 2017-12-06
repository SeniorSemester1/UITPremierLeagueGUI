#ifndef BESTFITPLAYERMANAGER_H
#define BESTFITPLAYERMANAGER_H
#include <PlayerManager.h>

class BestFitPlayerManager : public PlayerManager
{
public:
    BestFitPlayerManager();
    BestFitPlayerManager(const PlayerManager &);
    bool addPlayer(PlayerRecord ) override;
};

#endif // BESTFITPLAYERMANAGER_H

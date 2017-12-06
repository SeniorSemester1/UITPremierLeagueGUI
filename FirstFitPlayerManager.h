#ifndef FIRSTFITPLAYERMANAGER_H
#define FIRSTFITPLAYERMANAGER_H
#include <PlayerManager.h>

class FirstFitPlayerManager : public PlayerManager
{
public:
    FirstFitPlayerManager();
    FirstFitPlayerManager(const PlayerManager &);
    bool addPlayer(PlayerRecord ) override;
};

#endif // FIRSTFITPLAYERMANAGER_H

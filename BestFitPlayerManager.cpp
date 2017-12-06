#include "BestFitPlayerManager.h"
#include <limits>

BestFitPlayerManager::BestFitPlayerManager()
{
    headNum = NONE_OF_NEXT_RECORD_AVAILABLE;
}

BestFitPlayerManager::BestFitPlayerManager(const PlayerManager &prevBF) {
    this->headNum = prevBF.getHeader();
    this->playersJoined = prevBF.getPlayersList();
}

bool BestFitPlayerManager::addPlayer(PlayerRecord newPlayer) {
    if (isPlayerExist(newPlayer)) {
        return false;
    }
    if (headNum == NONE_OF_NEXT_RECORD_AVAILABLE) {
        playersJoined.push_back(newPlayer);
    }
    else {

        int nextAvailPos = headNum;
        int bestFitSize = INT32_MAX;
        PlayerRecord* bestFitPlayerRecord = NULL;
        PlayerRecord* prevPlayerRecord = NULL;
        PlayerRecord* prevBestFitPlayerRecord = NULL;
        std::list<PlayerRecord>::iterator ite;

        do {
            ite = getNextAvailRecordByPosition(nextAvailPos);

            PlayerRecord* currPlayerRecord = &*ite;

            int redundantSpaces = currPlayerRecord->getSize() - newPlayer.getSize();

            //determine the best fit position for new record
            if (redundantSpaces >= 0 && redundantSpaces < bestFitSize) {
                bestFitPlayerRecord = currPlayerRecord;
                bestFitSize = redundantSpaces;
                prevBestFitPlayerRecord = prevPlayerRecord;
            }
            prevPlayerRecord = currPlayerRecord;
            nextAvailPos = currPlayerRecord->getNextAvailRecordPos();
        } while (nextAvailPos != -1);

        //None fit record in stack available record
        if (bestFitPlayerRecord == NULL) {
            playersJoined.push_back(newPlayer);
        } else {
            //Best fit position is in top of stack available record
            if (prevBestFitPlayerRecord != NULL) {
                prevBestFitPlayerRecord->setNextAvailRecordPos(bestFitPlayerRecord
                                                               ->getNextAvailRecordPos());
            }
            //Best fit position is in middle of stack available record
            else {
                headNum = bestFitPlayerRecord->getNextAvailRecordPos();
            }
            bestFitPlayerRecord->setName(newPlayer.getName());           
        }
    }
    return true;
}

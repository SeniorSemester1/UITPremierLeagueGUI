#include "FirstFitPlayerManager.h"

FirstFitPlayerManager::FirstFitPlayerManager()
{
    headNum = NONE_OF_NEXT_RECORD_AVAILABLE;
}

FirstFitPlayerManager::FirstFitPlayerManager(const PlayerManager &prevFF) {
    this->headNum = prevFF.getHeader();
    this->playersJoined = prevFF.getPlayersList();
}

bool FirstFitPlayerManager::addPlayer(PlayerRecord newPlayer) {
    if (isPlayerExist(newPlayer)) {
        return false;
    }
    if (headNum == NONE_OF_NEXT_RECORD_AVAILABLE) {
        playersJoined.push_back(newPlayer);
    }
    else {
        int nextAvailPos = headNum;
        std::list<PlayerRecord>::iterator ite;

        PlayerRecord* currRecord = NULL;
        PlayerRecord* prevRecord = NULL;

        do {
            ite = getNextAvailRecordByPosition(nextAvailPos); //go to the next position of stack available record

            currRecord = &*ite;
            int redundantSpaces = currRecord->getSize() - newPlayer.getSize();
            if (redundantSpaces >= 0) //compare to insert
            {
                //Insert at top of stack available record
                if (prevRecord != NULL) {
                    prevRecord->setNextAvailRecordPos(currRecord->getNextAvailRecordPos());
                }
                //Insert at middle of stack available record
                else {
                    headNum = currRecord->getNextAvailRecordPos();
                }
                currRecord->setName(newPlayer.getName());
                currRecord->setNextAvailRecordPos(-1);
                break;
            }

            prevRecord = currRecord;
            nextAvailPos = currRecord->getNextAvailRecordPos();

        } while (nextAvailPos != -1);
        //No fit position in stack available record => add to tail
        if(nextAvailPos == -1)
            playersJoined.push_back(newPlayer);
    }
    return true;
}

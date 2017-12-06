#include "ClubRecord.h"
#include <BestFitPlayerManager.h>
#include <FirstFitPlayerManager.h>

#define FIRST_FIT_MODE 1
#define BEST_FIT_MODE 0

ClubRecord::ClubRecord() {

}

ClubRecord::ClubRecord(std::string name) {
    this->name = name;
    this->nextAvalRecord = -1;
}

ClubRecord::ClubRecord(std::string name, int recordMode) {
    this->name = name;

    switch (recordMode) {
    case FIRST_FIT_MODE:
        this->playerManager = new FirstFitPlayerManager();
        break;
    case BEST_FIT_MODE:
        this->playerManager = new BestFitPlayerManager();
        break;
    default:
        break;
    }

}

ClubRecord& ClubRecord::operator =(const ClubRecord &prevClub) {
    if (this == &prevClub)
        return *this;
    this->name = prevClub.name;
    this->nextAvalRecord = prevClub.nextAvalRecord;
    this->RRN = prevClub.RRN;
    this->playerManager = prevClub.playerManager;
}

void ClubRecord::setName(std::string name)
{
    this->name = name;
}

void ClubRecord::setRRN(std::int32_t x)
{
    this->RRN = x;
}

void ClubRecord::setNextAvailRecord(int nextAvailRecord) {
    this->nextAvalRecord = nextAvailRecord;
}

void ClubRecord::setPlayerManager(PlayerManager* newPlayerManager) {
    this->playerManager = newPlayerManager;
}

bool ClubRecord::operator==(ClubRecord anotherClub) {
    if (name == anotherClub.getName())
        return true;
    return false;
}

bool ClubRecord::operator !=(ClubRecord anotherClub) {
    if (name == anotherClub.getName())
        return false;
    return true;
}

ClubRecord& ClubRecord::clone(ClubRecord prevClubRec, int recordMode) {
    ClubRecord* cloneClubRec = new ClubRecord();
    cloneClubRec->setName(prevClubRec.getName());
    cloneClubRec->setNextAvailRecord(prevClubRec.getNextAvailRecord());
    cloneClubRec->setRRN(prevClubRec.getRRN());
    if (prevClubRec.getPlayerManager() != NULL) {
        switch (recordMode) {
        case FIRST_FIT_MODE:
            cloneClubRec->setPlayerManager(new FirstFitPlayerManager(*prevClubRec.getPlayerManager()));
            break;
        case BEST_FIT_MODE:
            cloneClubRec->setPlayerManager(new BestFitPlayerManager(*prevClubRec.getPlayerManager()));
            break;
        default:
            break;
        }
    }
    else
        cloneClubRec->setPlayerManager(NULL);
    return *cloneClubRec;
}

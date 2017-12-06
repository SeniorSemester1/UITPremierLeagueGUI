#include "Season.h"

Season::Season()
{
    clubManager = new ClubManager();
}

Season& Season::clone(Season prevSeason, int recordMode) {
    Season* cloneSeason = new Season();
    cloneSeason->setClubManager(ClubManager::clone(*prevSeason.getClubManager(), recordMode));
    return *cloneSeason;
}

void Season::setClubManager(ClubManager &newClubManager) {
    this->clubManager = &newClubManager;
}


Season& Season::operator =(const Season &prevSeason) {
    if (this == &prevSeason)
        return *this;
    clubManager = prevSeason.clubManager;
}

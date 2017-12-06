#include "League.h"

League::League(int seasonNum, int mode)
{
    this->seasonNum = seasonNum;
    this->mode = mode;

}

Season League::getSeason(int idx) {
    return seasons[idx];
}

void League::addSeason(Season newSeason) {
    seasons.push_back(newSeason);
}

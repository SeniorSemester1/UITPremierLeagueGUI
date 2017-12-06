#ifndef SEASONCHANGEWRAPPER_H
#define SEASONCHANGEWRAPPER_H


class SeasonChangeWrapper
{
private:
    int clubChange;
    int playerChange;
public:
    SeasonChangeWrapper(int, int);
    int getClubChange() {return clubChange;}
    int getPlayerChange() {return playerChange;}
};

#endif // SEASONCHANGEWRAPPER_H

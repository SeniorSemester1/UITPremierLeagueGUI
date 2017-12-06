#ifndef CLUBCHANGEWRAPPER_H
#define CLUBCHANGEWRAPPER_H
#include <string>

class ClubChangeWrapper
{
private:
    int mode;
    std::string name;
public:
    ClubChangeWrapper(int, std::string);
    int getMode() { return mode; }
    std::string getName() { return name; }
};

#endif // CLUBCHANGEWRAPPER_H

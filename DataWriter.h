#ifndef DATAWRITER_H
#define DATAWRITER_H
#include <League.h>

class DataWriter
{
private:
    League* league;
    std::string writePath;
public:
    DataWriter();
    void writeClub2File();
    void writePlayer2File(ClubRecord, int);
    void writePlayer2File(ClubRecord );
    void setWritePath(std::string path);
    void setLeague(League* league);
};

#endif // DATAWRITER_H

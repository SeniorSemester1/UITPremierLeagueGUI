#ifndef DATAWRITER_H
#define DATAWRITER_H
#include <League.h>

class DataWriter
{
private:
    League* league;
public:
    DataWriter(League* league);
    void writeClub2File(std::string );
    void writePlayer2File(ClubRecord, int);
    void writePlayer2File(ClubRecord );
};

#endif // DATAWRITER_H

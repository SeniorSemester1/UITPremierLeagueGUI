#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class PlayerRecord
{
private:
    std::string name;
    int size;
    int nextAvailRecordPos = -1;
public:
    PlayerRecord(std::string );

    std::string getName() {return name;}
    int getSize() {return size;}
    int getNextAvailRecordPos() { return nextAvailRecordPos; }

    void setName(std::string);
    void setSize(int );
    void setNextAvailRecordPos(int );

    PlayerRecord& operator =(const PlayerRecord &);
    bool operator ==(PlayerRecord );
    bool operator !=(PlayerRecord );
};

#endif // PLAYER_H

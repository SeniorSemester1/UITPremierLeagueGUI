#include "PlayerRecord.h"

#define BYTE_OF_RECORD_SIZE 1
#define BYTE_OF_SEPARATE_SIGN 1

PlayerRecord::PlayerRecord(std::string name) {
    this->name = name;
    this->size = name.size() + BYTE_OF_RECORD_SIZE + BYTE_OF_SEPARATE_SIGN;
}

void PlayerRecord::setName(std::string name) {
    this->name = name;
}

void PlayerRecord::setSize(int size) {
    this->size = size;
}

void PlayerRecord::setNextAvailRecordPos(int nextAvailRecordPos) {
    this->nextAvailRecordPos = nextAvailRecordPos;
}

bool PlayerRecord::operator ==(PlayerRecord anotherPlayer) {
    if (name == anotherPlayer.getName())
        return true;
    return false;
}

bool PlayerRecord::operator !=(PlayerRecord anotherPlayer) {
    if (name == anotherPlayer.getName())
        return false;
    return true;
}

PlayerRecord& PlayerRecord::operator =(const PlayerRecord &prevPlayerRec) {
    if (this == &prevPlayerRec)
        return *this;
    this->name = prevPlayerRec.name;
    this->nextAvailRecordPos = prevPlayerRec.nextAvailRecordPos;
    this->size = prevPlayerRec.size;
}


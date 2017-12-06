#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger
{
private:
    Logger();
public:
    static std::string logStr;

//    static const int WRONG_SEASON_NUMBER;
//    static const int WRONG_RECORD_MODE;
//    static const int WRONG_DML_MODE;
//    static const int WRONG_CLUB_CHANGE;
//    static const int WRONG_PLAYER_CHANGE;
//    static const int CLUB_SIZE_TOO_LONG;
//    static const int CLUB_SIZE_TOO_SHORT;
//    static const int CLUB_NOT_EXIST;
//    static const int CLUB_ALREADY_EXIST;
//    static const int PLAYER_NOT_EXIST;
//    static const int PLAYER_ALREADY_EXIST;

//    static const int QUIT_NEEDED_SIGNAL;

    static const std::string WRONG_SEASON_NUMBER_MSG;
    static const std::string WRONG_RECORD_MODE_MSG;
    static const std::string WRONG_DML_MODE_MSG;
    static const std::string WRONG_CLUB_CHANGE_MSG;
    static const std::string WRONG_PLAYER_CHANGE_MSG;
    static const std::string CLUB_SIZE_TOO_LONG_MSG;
    static const std::string CLUB_SIZE_TOO_SHORT_MSG;
    static const std::string CLUB_NOT_EXIST_MSG;
    static const std::string CLUB_ALREADY_EXIST_MSG;
    static const std::string PLAYER_NOT_EXIST_MSG;
    static const std::string PLAYER_ALREADY_EXIST_MSG;

    static const int WRONG_SEASON_NUMBER = 1;
    static const int WRONG_RECORD_MODE = 2;
    static const int WRONG_DML_MODE = 3;
    static const int WRONG_CLUB_CHANGE = 4;
    static const int WRONG_PLAYER_CHANGE = 5;
    static const int CLUB_SIZE_TOO_LONG = 6;
    static const int CLUB_SIZE_TOO_SHORT = 7;
    static const int CLUB_NOT_EXIST = 8;
    static const int CLUB_ALREADY_EXIST = 9;
    static const int PLAYER_NOT_EXIST = 10;
    static const int PLAYER_ALREADY_EXIST = 11;

    static const int QUIT_NEEDED_SIGNAL = -1;

//    static const std::string WRONG_SEASON_NUMBER_MSG = "Wrong season number\n";
//    static const std::string WRONG_RECORD_MODE_MSG = "Wrong record mode\n";
//    static const std::string WRONG_DML_MODE_MSG = "Not add or remove mode\n";
//    static const std::string WRONG_CLUB_CHANGE_MSG = "Wrong club change number\n";
//    static const std::string WRONG_PLAYER_CHANGE_MSG = "Wrong player change number\n";
//    static const std::string CLUB_SIZE_TOO_LONG_MSG = "Club size is too long (> 3)\n";
//    static const std::string CLUB_SIZE_TOO_SHORT_MSG = "Club size is too short (< 3)\n";
//    static const std::string CLUB_NOT_EXIST_MSG = "Club is not exist\n";
//    static const std::string CLUB_ALREADY_EXIST_MSG = "Club has already exist\n";
//    static const std::string PLAYER_NOT_EXIST_MSG = "Player is not exist\n";
//    static const std::string PLAYER_ALREADY_EXIST_MSG = "Player has already exist\n";
};

#endif // LOGGER_H

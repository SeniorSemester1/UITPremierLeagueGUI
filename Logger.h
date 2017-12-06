#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger
{
private:
    Logger();
public:
    static std::string logStr;

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

    static const int QUIT_NEEDED_SIGNAL = -1;
};

#endif // LOGGER_H

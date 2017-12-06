#include "Logger.h"

Logger::Logger()
{

}

std::string Logger::logStr = "";

//int Logger::WRONG_SEASON_NUMBER = 1;
//int Logger::WRONG_RECORD_MODE = 2;
//int Logger::WRONG_DML_MODE = 3;
//int Logger::WRONG_CLUB_CHANGE = 4;
//int Logger::WRONG_PLAYER_CHANGE = 5;
//int Logger::CLUB_SIZE_TOO_LONG = 6;
//int Logger::CLUB_SIZE_TOO_SHORT = 7;
//int Logger::CLUB_NOT_EXIST = 8;
//int Logger::CLUB_ALREADY_EXIST = 9;
//int Logger::PLAYER_NOT_EXIST = 10;
//int Logger::PLAYER_ALREADY_EXIST = 11;

//int Logger::QUIT_NEEDED_SIGNAL = -1;

const std::string Logger::WRONG_SEASON_NUMBER_MSG = "Wrong season number\n";
const std::string Logger::WRONG_RECORD_MODE_MSG = "Wrong record mode\n";
const std::string Logger::WRONG_DML_MODE_MSG = "Not add or remove mode\n";
const std::string Logger::WRONG_CLUB_CHANGE_MSG = "Wrong club change number\n";
const std::string Logger::WRONG_PLAYER_CHANGE_MSG = "Wrong player change number\n";
const std::string Logger::CLUB_SIZE_TOO_LONG_MSG = "Club size is too long (> 3)\n";
const std::string Logger::CLUB_SIZE_TOO_SHORT_MSG = "Club size is too short (< 3)\n";
const std::string Logger::CLUB_NOT_EXIST_MSG = "Club is not exist\n";
const std::string Logger::CLUB_ALREADY_EXIST_MSG = "Club has already exist\n";
const std::string Logger::PLAYER_NOT_EXIST_MSG = "Player is not exist\n";
const std::string Logger::PLAYER_ALREADY_EXIST_MSG = "Player has already exist\n";

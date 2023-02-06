#pragma once

#include <ctime>
#include <iostream>
#include <string>

namespace lifesim {

#define FATAL       0x00
#define ERROR       0x01
#define WARNING     0x02
#define INFO        0x03
#define DEBUG       0x04

#define LOG_FMT                "[%s][%s][%s:%d]: %s"

#define NEWLINE     "\n"

#define FATAL_TAG   "FATAL"
#define ERROR_TAG   "ERROR"
#define WARNING_TAG "WARNING"
#define INFO_TAG    "INFO"
#define DEBUG_TAG   "DEBUG"

#define PRINTFUNCTION(format, ...)      printf(format, __VA_ARGS__)

#ifndef LOG_LEVEL
#define LOG_LEVEL   DEBUG
#endif

#define LOG(level, msg)   lifesim::LogWrapper(__FILE__, __LINE__, level, msg)

#define PRINT(msg)      lifesim::PrintWrapper("%s", msg);

void PrintWrapper(std::string format, std::string msg);

void PrintWrapper(std::string format, char* msg);

std::string GetTime();

void LogWrapper(const char* file, int line, int level, std::string msg);

}

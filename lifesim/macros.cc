#include "lifesim/macros.h"

namespace lifesim {

void PrintWrapper(std::string format, std::string msg) {
    printf(format.c_str(), msg.c_str());
}

void PrintWrapper(std::string format, char* msg) {
    printf(format.c_str(), msg);
}

std::string GetTime() {
    time_t now = time(0);
    struct tm time_struct;
    time_struct = *localtime(&now);
    std::string time_string = std::to_string(time_struct.tm_hour) + ":";
    time_string += std::to_string(time_struct.tm_min) + ":";
    time_string += std::to_string(time_struct.tm_sec);
    return time_string;
}

void LogWrapper(const char* file, int line, int level, std::string msg){
    const char* level_str;
    if (LOG_LEVEL < level) {
        return;
    }
    switch(level) {
        case INFO:
            level_str = INFO_TAG;
            break;
        case WARNING:
            level_str = WARNING_TAG;
            break;
        case ERROR:
            level_str = ERROR_TAG;
            break;
        case FATAL:
            level_str = FATAL_TAG;
            break;
        case DEBUG:
            level_str = DEBUG_TAG;
            break;
        case TRACE:
        default:
            level_str = TRACE_TAG;
            break;
    }
    PRINTFUNCTION(LOG_FMT, level_str, GetTime().c_str(), file, line, (msg + NEWLINE).c_str());
}

}

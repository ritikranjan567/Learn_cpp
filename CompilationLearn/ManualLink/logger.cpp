#include<iostream>
#include "logger.h"

void logError(std::string msg) {
    std::cout << "[ERROR]: " << msg << std::endl;
}

void logDebug(std::string msg) {
    std::cout << "[Debug]: " << msg << std::endl;
}

#include "Logger.h"
#include <ctime>
#include <iomanip>
#include <iostream>

Logger::Logger() {
    fout.open("system.log", std::ios::app);
}
Logger::~Logger() {
    if (fout.is_open()) fout.close();
}
Logger& Logger::getInstance() {
    static Logger logger;
    return logger;
}
void Logger::log(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx);
    std::time_t t = std::time(nullptr);
    fout << "[" << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S") << "] "
         << msg << std::endl;
}
void Logger::close() {
    std::lock_guard<std::mutex> lock(mtx);
    if (fout.is_open()) fout.close();
}
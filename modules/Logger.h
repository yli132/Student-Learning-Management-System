#pragma once
#include <string>
#include <fstream>
#include <mutex>

/**
 * @brief 日志管理类，单例模式
 */
class Logger {
private:
    std::ofstream fout;
    std::mutex mtx;
    Logger();
public:
    static Logger& getInstance();
    void log(const std::string& msg);
    void close();
    ~Logger();
};
#include "Logger.h"
#include <iostream>

void testLogger() {
    Logger& logger = Logger::getInstance();
    logger.log("测试日志1: 系统启动");
    logger.log("测试日志2: 操作成功");
    logger.log("测试日志3: 用户退出");
    logger.close();
    std::cout << "Logger模块日志写入完毕，请检查 system.log 文件。" << std::endl;
}

int main() {
    testLogger();
    return 0;
}
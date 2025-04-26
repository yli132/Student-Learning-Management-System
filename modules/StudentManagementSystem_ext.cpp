#include "StudentManagementSystem.h"
#include <iostream>
#include <iomanip>
#include <string>


void printCourseAverage(const StudentManagementSystem& sms, const std::string& cid) {
    const auto& scores = sms.getScores();
    int count = 0;
    double sum = 0.0;
    for (const auto& pair : scores) {
        double score = pair.second.getScore(cid);
        if (score >= 0.0) { // 假定 getScore 返回负值表示无此课程成绩
            sum += score;
            ++count;
        }
    }
    if (count == 0) {
        std::cout << "课程[" << cid << "]没有成绩记录" << std::endl;
    } else {
        std::cout << "课程[" << cid << "]平均分: " << std::fixed << std::setprecision(2) << (sum / count) << std::endl;
    }
}
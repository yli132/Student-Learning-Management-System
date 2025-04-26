#include "Score.h"
#include <iostream>

Score::Score() {}

Score::Score(const std::string& sid)
    : studentId(sid) {}

void Score::setScore(const std::string& courseId, double score) {
    courseScores[courseId] = score;
}

double Score::getScore(const std::string& courseId) const {
    auto it = courseScores.find(courseId);
    if (it != courseScores.end())
        return it->second;
    return -1.0; // -1.0 表示未录入
}

void Score::display() const {
    std::cout << "学生学号: " << studentId << " 成绩列表:" << std::endl;
    for (const auto& pair : courseScores) {
        std::cout << "课程编号: " << pair.first << " -> 分数: " << pair.second << std::endl;
    }
}
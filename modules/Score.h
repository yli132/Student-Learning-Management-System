#pragma once
#include <string>
#include <map>

/**
 * @brief 分数管理：存储学生各门课程的成绩
 */
class Score {
public:
    std::string studentId; ///< 学生学号
    std::map<std::string, double> courseScores; ///< 课程号->成绩

    Score();
    Score(const std::string& sid);

    void setScore(const std::string& courseId, double score);
    double getScore(const std::string& courseId) const;
    void display() const;
    // TODO: 可扩展成绩录入时间、成绩类型等
};
#pragma once
#include <string>
#include <set>

/**
 * @brief 课程类
 */
class Course {
public:
    std::string courseId;        ///< 课程编号
    std::string courseName;      ///< 课程名称
    std::string teacherName;     ///< 任课教师
    int credit;                  ///< 学分
    std::set<std::string> studentIds; ///< 选课学生学号集合

    // 构造函数
    Course();
    Course(const std::string& id, const std::string& name, const std::string& teacher, int credit);

    // 显示课程信息
    void display() const;

    // 添加/移除学生
    void addStudent(const std::string& studentId);
    void removeStudent(const std::string& studentId);

    // TODO: 可扩展课程时间、地点、容量等
};
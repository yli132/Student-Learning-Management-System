#pragma once
#include "Student.h"
#include "Course.h"
#include "Score.h"
#include <map>
#include <string>
#include <vector>

/**
 * @brief 学籍管理系统类，包含学生、课程、成绩管理等
 */
class StudentManagementSystem {
private:
    std::map<std::string, Student> students;   ///< 学号 -> 学生
    std::map<std::string, Course> courses;     ///< 课程编号 -> 课程
    std::map<std::string, Score> scores;       ///< 学号 -> 成绩

public:
    // 学生管理
    bool addStudent(const Student& student);
    bool removeStudent(const std::string& studentId);
    bool updateStudent(const std::string& studentId, const std::string& newName, int newAge, const std::string& newGender, const std::string& newDept);
    void queryStudent(const std::string& studentId) const;
    void listAllStudents() const;

    // 课程管理
    bool addCourse(const Course& course);
    bool removeCourse(const std::string& courseId);
    void queryCourse(const std::string& courseId) const;
    void listAllCourses() const;

    // 选课退课
    bool enrollCourse(const std::string& studentId, const std::string& courseId);
    bool dropCourse(const std::string& studentId, const std::string& courseId);
    void listStudentCourses(const std::string& studentId) const;
    void listCourseStudents(const std::string& courseId) const;

    // 成绩管理
    void setScore(const std::string& studentId, const std::string& courseId, double score);
    void queryScore(const std::string& studentId) const;
    void queryScoreForCourse(const std::string& courseId) const;
    void querySingleScore(const std::string& studentId, const std::string& courseId) const;

    // 数据持久化
    void saveAll(const std::string& dir) const;
    void loadAll(const std::string& dir);

    // 新增：获取成绩map的只读引用
    const std::map<std::string, Score>& getScores() const { return scores; }
};
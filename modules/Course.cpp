#include "Course.h"
#include <iostream>

Course::Course() : credit(0) {}

Course::Course(const std::string& id, const std::string& name, const std::string& teacher, int c)
    : courseId(id), courseName(name), teacherName(teacher), credit(c) {}

void Course::display() const {
    std::cout << "课程编号: " << courseId
              << ", 课程名称: " << courseName
              << ", 教师: " << teacherName
              << ", 学分: " << credit
              << std::endl;
    std::cout << "选课学生学号: ";
    for (const auto& sid : studentIds) {
        std::cout << sid << " ";
    }
    std::cout << std::endl;
}

void Course::addStudent(const std::string& studentId) {
    studentIds.insert(studentId);
}

void Course::removeStudent(const std::string& studentId) {
    studentIds.erase(studentId);
}
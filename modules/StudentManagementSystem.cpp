#include "StudentManagementSystem.h"
#include <iostream>

// 学生管理
bool StudentManagementSystem::addStudent(const Student& student) {
    if (students.count(student.studentId)) return false;
    students[student.studentId] = student;
    return true;
}
bool StudentManagementSystem::removeStudent(const std::string& studentId) {
    return students.erase(studentId) > 0;
}
bool StudentManagementSystem::updateStudent(const std::string& studentId, const std::string& newName, int newAge, const std::string& newGender, const std::string& newDept) {
    auto it = students.find(studentId);
    if (it == students.end()) return false;
    it->second.setName(newName);
    it->second.setAge(newAge);
    it->second.setGender(newGender);
    it->second.setDepartment(newDept);
    return true;
}
void StudentManagementSystem::queryStudent(const std::string& studentId) const {
    auto it = students.find(studentId);
    if (it != students.end()) it->second.display();
    else std::cout << "未找到该学生！" << std::endl;
}
void StudentManagementSystem::listAllStudents() const {
    for (const auto& p : students) p.second.display();
}

// 课程管理
bool StudentManagementSystem::addCourse(const Course& course) {
    if (courses.count(course.courseId)) return false;
    courses[course.courseId] = course;
    return true;
}
bool StudentManagementSystem::removeCourse(const std::string& courseId) {
    return courses.erase(courseId) > 0;
}
void StudentManagementSystem::queryCourse(const std::string& courseId) const {
    auto it = courses.find(courseId);
    if (it != courses.end()) it->second.display();
    else std::cout << "未找到该课程！" << std::endl;
}
void StudentManagementSystem::listAllCourses() const {
    for (const auto& p : courses) p.second.display();
}

// 选课退课
bool StudentManagementSystem::enrollCourse(const std::string& studentId, const std::string& courseId) {
    auto stuIt = students.find(studentId);
    auto couIt = courses.find(courseId);
    if (stuIt == students.end() || couIt == courses.end()) return false;
    stuIt->second.enrollCourse(courseId);
    couIt->second.addStudent(studentId);
    return true;
}
bool StudentManagementSystem::dropCourse(const std::string& studentId, const std::string& courseId) {
    auto stuIt = students.find(studentId);
    auto couIt = courses.find(courseId);
    if (stuIt == students.end() || couIt == courses.end()) return false;
    stuIt->second.dropCourse(courseId);
    couIt->second.removeStudent(studentId);
    return true;
}
void StudentManagementSystem::listStudentCourses(const std::string& studentId) const {
    auto it = students.find(studentId);
    if (it != students.end()) {
        std::cout << "学生[" << studentId << "]已选课程: ";
        for (const auto& cid : it->second.enrolledCourseIds) std::cout << cid << " ";
        std::cout << std::endl;
    } else {
        std::cout << "未找到该学生！" << std::endl;
    }
}
void StudentManagementSystem::listCourseStudents(const std::string& courseId) const {
    auto it = courses.find(courseId);
    if (it != courses.end()) {
        std::cout << "课程[" << courseId << "]选课学生: ";
        for (const auto& sid : it->second.studentIds) std::cout << sid << " ";
        std::cout << std::endl;
    } else {
        std::cout << "未找到该课程！" << std::endl;
    }
}

// 成绩管理
void StudentManagementSystem::setScore(const std::string& studentId, const std::string& courseId, double score) {
    if (!students.count(studentId) || !courses.count(courseId)) return;
    if (!scores.count(studentId)) scores[studentId] = Score(studentId);
    scores[studentId].setScore(courseId, score);
}
void StudentManagementSystem::queryScore(const std::string& studentId) const {
    auto it = scores.find(studentId);
    if (it != scores.end()) it->second.display();
    else std::cout << "未找到该学生成绩！" << std::endl;
}
void StudentManagementSystem::queryScoreForCourse(const std::string& courseId) const {
    std::cout << "课程[" << courseId << "]成绩列表:" << std::endl;
    for (const auto& pair : scores) {
        double sc = pair.second.getScore(courseId);
        if (sc >= 0.0)
            std::cout << "学号: " << pair.first << " 分数: " << sc << std::endl;
    }
}
void StudentManagementSystem::querySingleScore(const std::string& studentId, const std::string& courseId) const {
    auto it = scores.find(studentId);
    if (it != scores.end()) {
        double sc = it->second.getScore(courseId);
        if (sc >= 0.0)
            std::cout << "成绩: " << sc << std::endl;
        else
            std::cout << "未找到成绩记录！" << std::endl;
    } else {
        std::cout << "未找到该学生成绩！" << std::endl;
    }
}

// 数据持久化（可根据实际需求实现）
void StudentManagementSystem::saveAll(const std::string& dir) const {}
void StudentManagementSystem::loadAll(const std::string& dir) {}
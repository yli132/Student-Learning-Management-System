#include "Student.h"

// 默认构造函数
Student::Student() : age(0) {}

Student::Student(const std::string& id, const std::string& name, int age, const std::string& gender, const std::string& department)
    : studentId(id), name(name), age(age), gender(gender), department(department) {}

// 显示学生基本信息和所选课程
void Student::display() const {
    std::cout << "学号: " << studentId
              << ", 姓名: " << name
              << ", 年龄: " << age
              << ", 性别: " << gender
              << ", 院系: " << department << std::endl;
    std::cout << "地址: ";
    for (const auto& addr : address) {
        std::cout << addr << "; ";
    }
    std::cout << std::endl;
    std::cout << "已选课程编号: ";
    for (const auto& cid : enrolledCourseIds) {
        std::cout << cid << " ";
    }
    std::cout << std::endl;
}

// 选课
void Student::enrollCourse(const std::string& courseId) {
    enrolledCourseIds.insert(courseId);
}

// 退课
void Student::dropCourse(const std::string& courseId) {
    enrolledCourseIds.erase(courseId);
}

void Student::setAddress(const std::vector<std::string>& addr) {
    address = addr;
}
void Student::setName(const std::string& n) {
    name = n;
}
void Student::setAge(int a) {
    age = a;
}
void Student::setGender(const std::string& g) {
    gender = g;
}
void Student::setDepartment(const std::string& d) {
    department = d;
}
#pragma once
#include <string>
#include <set>
#include <vector>
#include <iostream>

/**
 * @brief 学生类，包含学生基础信息及选课信息
 */
class Student {
public:
    std::string studentId;                ///< 学号
    std::string name;                     ///< 姓名
    int age;                              ///< 年龄
    std::string gender;                   ///< 性别
    std::string department;               ///< 所属院系
    std::vector<std::string> address;     ///< 地址（可多行）
    std::set<std::string> enrolledCourseIds; ///< 已选课程编号集合

    // 构造函数
    Student();
    Student(const std::string& id, const std::string& name, int age, const std::string& gender, const std::string& department);

    // 显示学生信息
    void display() const;

    // 增加/移除选课
    void enrollCourse(const std::string& courseId);
    void dropCourse(const std::string& courseId);

    // 设置和获取属性
    void setAddress(const std::vector<std::string>& addr);
    void setName(const std::string& name);
    void setAge(int age);
    void setGender(const std::string& gender);
    void setDepartment(const std::string& department);

    // TODO: 可扩展更多学生属性，如联系方式、入学年份等
};
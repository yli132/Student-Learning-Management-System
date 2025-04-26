#pragma once
#include <string>
#include <regex>

/**
 * @brief 输入校验工具类
 */
class Validator {
public:
    // 校验学号格式（如：s12345）
    static bool validateStudentId(const std::string& id);

    // 校验课程编号格式（如：c101）
    static bool validateCourseId(const std::string& id);

    // 校验姓名（只允许中英文）
    static bool validateName(const std::string& name);

    // 校验年龄（合法范围）
    static bool validateAge(int age);

    // 校验性别
    static bool validateGender(const std::string& gender);

    // 校验分数（0~100）
    static bool validateScore(double score);
};
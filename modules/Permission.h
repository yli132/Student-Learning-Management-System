#pragma once
#include <string>
#include <set>

/**
 * @brief 权限管理
 */
class Permission {
public:
    enum Role {
        ADMIN,
        TEACHER,
        STUDENT
    };
    static std::string roleToString(Role r);
    static bool canEditStudent(Role r);
    static bool canEditCourse(Role r);
    static bool canEditScore(Role r);
};
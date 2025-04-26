#pragma once
#include <string>
#include "Permission.h"

/**
 * @brief 用户类（登录/权限）
 */
class User {
public:
    std::string username;
    std::string password;
    Permission::Role role;
    User(const std::string& uname, const std::string& pwd, Permission::Role r);
    bool checkPassword(const std::string& pwd) const;
};
#pragma once
#include "User.h"
#include <vector>

/**
 * @brief 登录认证系统
 */
class AuthSystem {
private:
    std::vector<User> users;
    int currentUserIdx;
public:
    AuthSystem();
    void addUser(const User& user);
    bool login(const std::string& username, const std::string& password);
    void logout();
    const User* currentUser() const;
};
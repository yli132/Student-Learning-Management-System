#include "User.h"

User::User(const std::string& uname, const std::string& pwd, Permission::Role r)
    : username(uname), password(pwd), role(r) {}

bool User::checkPassword(const std::string& pwd) const {
    return pwd == password;
}
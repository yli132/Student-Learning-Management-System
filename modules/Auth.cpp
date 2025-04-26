#include "Auth.h"

AuthSystem::AuthSystem() : currentUserIdx(-1) {}

void AuthSystem::addUser(const User& user) {
    users.push_back(user);
}
bool AuthSystem::login(const std::string& username, const std::string& password) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].username == username && users[i].checkPassword(password)) {
            currentUserIdx = static_cast<int>(i);
            return true;
        }
    }
    return false;
}
void AuthSystem::logout() {
    currentUserIdx = -1;
}
const User* AuthSystem::currentUser() const {
    if (currentUserIdx < 0 || currentUserIdx >= (int)users.size()) return nullptr;
    return &users[currentUserIdx];
}
#include "Auth.h"
#include <cassert>
#include <iostream>

void testAuthSystem() {
    AuthSystem auth;
    auth.addUser(User("admin", "123", Permission::ADMIN));
    auth.addUser(User("teacher", "abc", Permission::TEACHER));
    auth.addUser(User("stu", "stu", Permission::STUDENT));

    assert(auth.login("admin", "123"));
    assert(auth.currentUser()->role == Permission::ADMIN);
    auth.logout();
    assert(auth.currentUser() == nullptr);

    assert(auth.login("teacher", "abc"));
    assert(auth.currentUser()->role == Permission::TEACHER);

    assert(!auth.login("teacher", "wrong"));
    auth.logout();
    assert(auth.login("stu", "stu"));
    assert(auth.currentUser()->username == "stu");
}

int main() {
    testAuthSystem();
    std::cout << "Auth模块单元测试全部通过！" << std::endl;
    return 0;
}
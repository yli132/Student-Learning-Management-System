#include "Permission.h"
#include <cassert>
#include <iostream>

void testPermission() {
    using Role = Permission::Role;
    assert(Permission::roleToString(Role::ADMIN) == "管理员");
    assert(Permission::roleToString(Role::TEACHER) == "教师");
    assert(Permission::roleToString(Role::STUDENT) == "学生");
    assert(Permission::canEditStudent(Role::ADMIN));
    assert(!Permission::canEditStudent(Role::TEACHER));
    assert(!Permission::canEditStudent(Role::STUDENT));
    assert(Permission::canEditCourse(Role::ADMIN));
    assert(Permission::canEditCourse(Role::TEACHER));
    assert(!Permission::canEditCourse(Role::STUDENT));
    assert(Permission::canEditScore(Role::ADMIN));
    assert(Permission::canEditScore(Role::TEACHER));
    assert(!Permission::canEditScore(Role::STUDENT));
}

int main() {
    testPermission();
    std::cout << "Permission模块单元测试全部通过！" << std::endl;
    return 0;
}
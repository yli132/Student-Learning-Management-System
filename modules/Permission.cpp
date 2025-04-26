#include "Permission.h"

std::string Permission::roleToString(Role r) {
    switch(r) {
        case ADMIN: return "管理员";
        case TEACHER: return "教师";
        case STUDENT: return "学生";
        default: return "未知";
    }
}
bool Permission::canEditStudent(Role r) {
    return r == ADMIN;
}
bool Permission::canEditCourse(Role r) {
    return r == ADMIN || r == TEACHER;
}
bool Permission::canEditScore(Role r) {
    return r == ADMIN || r == TEACHER;
}
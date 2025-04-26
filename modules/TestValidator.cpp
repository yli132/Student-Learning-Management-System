#include "Validator.h"
#include <cassert>
#include <iostream>

void testStudentId() {
    assert(Validator::validateStudentId("s1234"));
    assert(Validator::validateStudentId("s20250001"));
    assert(!Validator::validateStudentId("x1234"));
    assert(!Validator::validateStudentId("s12"));
}

void testCourseId() {
    assert(Validator::validateCourseId("c101"));
    assert(!Validator::validateCourseId("d101"));
    assert(!Validator::validateCourseId("c10"));
}

void testName() {
    assert(Validator::validateName("王小明"));
    assert(Validator::validateName("John Doe"));
    assert(!Validator::validateName("王@明"));
    assert(!Validator::validateName(""));
}

void testAge() {
    assert(Validator::validateAge(20));
    assert(!Validator::validateAge(8));
    assert(!Validator::validateAge(105));
}

void testGender() {
    assert(Validator::validateGender("男"));
    assert(Validator::validateGender("female"));
    assert(!Validator::validateGender("未知"));
}

void testScore() {
    assert(Validator::validateScore(0));
    assert(Validator::validateScore(100));
    assert(Validator::validateScore(60.5));
    assert(!Validator::validateScore(-1));
    assert(!Validator::validateScore(120));
}

int main() {
    testStudentId();
    testCourseId();
    testName();
    testAge();
    testGender();
    testScore();
    std::cout << "Validator模块单元测试全部通过！" << std::endl;
    return 0;
}
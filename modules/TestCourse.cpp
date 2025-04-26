#include "Course.h"
#include <cassert>
#include <iostream>

void testCourseCreateAndDisplay() {
    Course course("c300", "数据结构", "王老师", 4);
    course.display();
    assert(course.courseId == "c300");
    assert(course.courseName == "数据结构");
    assert(course.teacherName == "王老师");
    assert(course.credit == 4);
}

void testCourseAddAndRemoveStudent() {
    Course course("c301", "算法分析", "李老师", 3);
    course.addStudent("s2001");
    course.addStudent("s2002");
    assert(course.studentIds.count("s2001") == 1);
    course.removeStudent("s2001");
    assert(course.studentIds.count("s2001") == 0);
}

int main() {
    testCourseCreateAndDisplay();
    testCourseAddAndRemoveStudent();
    std::cout << "Course模块单元测试全部通过！" << std::endl;
    return 0;
}
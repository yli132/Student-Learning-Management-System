#include "Student.h"
#include <cassert>
#include <iostream>

void testStudentCreateAndDisplay() {
    Student stu("s2025001", "王小明", 20, "男", "软件工程");
    stu.setAddress({"北京市海淀区", "清华科技园"});
    stu.enrollCourse("c101");
    stu.enrollCourse("c102");
    stu.display();
    assert(stu.studentId == "s2025001");
    assert(stu.name == "王小明");
    assert(stu.age == 20);
    assert(stu.gender == "男");
    assert(stu.department == "软件工程");
    assert(stu.enrolledCourseIds.count("c101") == 1);
    assert(stu.enrolledCourseIds.count("c102") == 1);
}

void testStudentSelectAndDropCourse() {
    Student stu("s2025002", "李华", 19, "女", "数学");
    stu.enrollCourse("c201");
    stu.enrollCourse("c202");
    assert(stu.enrolledCourseIds.count("c201") == 1);
    stu.dropCourse("c201");
    assert(stu.enrolledCourseIds.count("c201") == 0);
}

void testStudentSetters() {
    Student stu;
    stu.setName("张三");
    stu.setAge(22);
    stu.setGender("男");
    stu.setDepartment("物理");
    stu.setAddress({"上海市徐汇区", "华山路"});
    assert(stu.name == "张三");
    assert(stu.age == 22);
    assert(stu.gender == "男");
    assert(stu.department == "物理");
    assert(stu.address.size() == 2);
}

int main() {
    testStudentCreateAndDisplay();
    testStudentSelectAndDropCourse();
    testStudentSetters();
    std::cout << "Student模块单元测试全部通过！" << std::endl;
    return 0;
}
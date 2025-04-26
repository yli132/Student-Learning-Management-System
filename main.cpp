#include <iostream>
#include "modules/StudentManagementSystem.h"
#include "modules/Validator.h"
#include "modules/Logger.h"
#include "modules/Auth.h"
#include "modules/Permission.h"

void printMenu() {
    std::cout << "====== 学生学籍管理系统菜单 ======" << std::endl;
    std::cout << "1. 添加学生" << std::endl;
    std::cout << "2. 删除学生" << std::endl;
    std::cout << "3. 修改学生信息" << std::endl;
    std::cout << "4. 查询学生" << std::endl;
    std::cout << "5. 列出所有学生" << std::endl;
    std::cout << "6. 添加课程" << std::endl;
    std::cout << "7. 删除课程" << std::endl;
    std::cout << "8. 查询课程" << std::endl;
    std::cout << "9. 列出所有课程" << std::endl;
    std::cout << "10. 学生选课" << std::endl;
    std::cout << "11. 学生退课" << std::endl;
    std::cout << "12. 查询学生已选课程" << std::endl;
    std::cout << "13. 查询课程选课学生" << std::endl;
    std::cout << "14. 录入成绩" << std::endl;
    std::cout << "15. 查询学生成绩" << std::endl;
    std::cout << "16. 查询课程成绩" << std::endl;
    std::cout << "0. 退出系统" << std::endl;
}

int main() {
    StudentManagementSystem sms;
    AuthSystem auth;
    auth.addUser(User("admin", "admin123", Permission::ADMIN));
    auth.addUser(User("teacher", "teacher", Permission::TEACHER));
    auth.addUser(User("stu", "stu", Permission::STUDENT));

    std::string username, password;
    std::cout << "欢迎登录学生学籍管理系统，请输入用户名: ";
    std::cin >> username;
    std::cout << "请输入密码: ";
    std::cin >> password;
    if (!auth.login(username, password)) {
        std::cout << "登录失败，程序退出！" << std::endl;
        return 1;
    }
    Logger::getInstance().log(username + " 登录系统");

    int choice;
    while (true) {
        printMenu();
        std::cout << "当前用户：" << username << " (" << Permission::roleToString(auth.currentUser()->role) << ")\n";
        std::cout << "请输入操作编号: ";
        std::cin >> choice;
        if (choice == 0) break;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }
        // 权限控制
        if ((choice >= 1 && choice <= 5) && !Permission::canEditStudent(auth.currentUser()->role)) {
            std::cout << "没有操作学生信息的权限。\n";
            continue;
        }
        if ((choice >= 6 && choice <= 9) && !Permission::canEditCourse(auth.currentUser()->role)) {
            std::cout << "没有操作课程信息的权限。\n";
            continue;
        }
        Logger::getInstance().log(username + " 执行操作编号: " + std::to_string(choice));
        switch (choice) {
        case 1: {
            std::string id, name, gender, dept;
            int age;
            std::cout << "请输入学号: ";
            std::cin >> id;
            if (!Validator::validateStudentId(id)) {
                std::cout << "学号格式错误！" << std::endl;
                break;
            }
            std::cout << "请输入姓名: ";
            std::cin >> name;
            std::cout << "请输入年龄: ";
            std::cin >> age;
            std::cout << "请输入性别: ";
            std::cin >> gender;
            std::cout << "请输入院系: ";
            std::cin >> dept;
            Student stu(id, name, age, gender, dept);
            sms.addStudent(stu);
            break;
        }
        case 2: {
            std::string id;
            std::cout << "请输入要删除的学号: ";
            std::cin >> id;
            sms.removeStudent(id);
            break;
        }
        case 3: {
            std::string id, name, gender, dept;
            int age;
            std::cout << "请输入要修改的学号: ";
            std::cin >> id;
            std::cout << "新姓名: ";
            std::cin >> name;
            std::cout << "新年龄: ";
            std::cin >> age;
            std::cout << "新性别: ";
            std::cin >> gender;
            std::cout << "新院系: ";
            std::cin >> dept;
            sms.updateStudent(id, name, age, gender, dept);
            break;
        }
        case 4: {
            std::string id;
            std::cout << "请输入学号: ";
            std::cin >> id;
            sms.queryStudent(id);
            break;
        }
        case 5:
            sms.listAllStudents();
            break;
        case 6: {
            std::string cid, cname, tname;
            int credit;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            std::cout << "课程名称: ";
            std::cin >> cname;
            std::cout << "教师姓名: ";
            std::cin >> tname;
            std::cout << "学分: ";
            std::cin >> credit;
            Course c(cid, cname, tname, credit);
            sms.addCourse(c);
            break;
        }
        case 7: {
            std::string cid;
            std::cout << "请输入要删除的课程编号: ";
            std::cin >> cid;
            sms.removeCourse(cid);
            break;
        }
        case 8: {
            std::string cid;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            sms.queryCourse(cid);
            break;
        }
        case 9:
            sms.listAllCourses();
            break;
        case 10: {
            std::string sid, cid;
            std::cout << "请输入学号: ";
            std::cin >> sid;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            sms.enrollCourse(sid, cid);
            break;
        }
        case 11: {
            std::string sid, cid;
            std::cout << "请输入学号: ";
            std::cin >> sid;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            sms.dropCourse(sid, cid);
            break;
        }
        case 12: {
            std::string sid;
            std::cout << "请输入学号: ";
            std::cin >> sid;
            sms.listStudentCourses(sid);
            break;
        }
        case 13: {
            std::string cid;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            sms.listCourseStudents(cid);
            break;
        }
        case 14: {
            std::string sid, cid;
            double score;
            std::cout << "请输入学号: ";
            std::cin >> sid;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            std::cout << "请输入分数: ";
            std::cin >> score;
            if (!Validator::validateScore(score)) {
                std::cout << "分数无效！" << std::endl;
                break;
            }
            sms.setScore(sid, cid, score);
            break;
        }
        case 15: {
            std::string sid, cid;
            std::cout << "请输入学号: ";
            std::cin >> sid;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            const auto& scores = sms.getScores();
            double score = scores.count(sid) ? scores.at(sid).getScore(cid) : -1.0;
            if (score == -1.0) {
                std::cout << "未找到成绩记录！" << std::endl;
            } else {
                std::cout << "成绩: " << score << std::endl;
            }
            break;
        }
        case 16: {
            std::string cid;
            std::cout << "请输入课程编号: ";
            std::cin >> cid;
            sms.queryScoreForCourse(cid);
            break;
        }
        default:
            std::cout << "无效操作编号！" << std::endl;
            break;
        }
    }
    Logger::getInstance().log(username + " 退出系统");
    Logger::getInstance().close();
    std::cout << "退出系统！" << std::endl;
    return 0;
}
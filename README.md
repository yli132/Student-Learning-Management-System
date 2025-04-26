# 学生学籍管理系统（C++版，模块化）

## 项目简介

本项目是使用 C++ 实现的**学生学籍管理系统**，采用模块化设计，代码总量约2000行，包含完善的注释和丰富的功能。适合高校、教务系统的课程管理演示或 C++ OOP/数据结构/STL 教学实践。  
系统支持学生/课程/成绩的增删查改、选课、成绩管理、数据导入导出、权限与登录、日志、单元测试等业务功能，且所有功能均按模块分文件组织，便于维护和扩展。

---

## 目录结构

```
.
├── main.cpp
├── modules/
│   ├── Student.h / .cpp
│   ├── Course.h / .cpp
│   ├── Score.h / .cpp
│   ├── StudentManagementSystem.h / .cpp
│   ├── StudentManagementSystem_ext.h / .cpp
│   ├── Validator.h / .cpp
│   ├── Logger.h / .cpp
│   ├── Permission.h / .cpp
│   ├── User.h / .cpp
│   ├── Auth.h / .cpp
│   ├── DataExporter.h / .cpp
│   ├── DataImporter.h / .cpp
│   ├── 测试代码(TestStudent.cpp, TestCourse.cpp, ...)
│   ├── README.md / README_DATA.md
```

---

## 主要功能

- **学生管理**：添加、删除、修改、查询、批量导入、批量导出
- **课程管理**：添加、删除、修改、查询、批量操作
- **成绩管理**：录入、查询、批量操作、统计
- **选课退课**：学生选课/退课，查询学生/课程互相关联
- **数据导入导出**：CSV/JSON格式进出，便于与Excel/第三方系统对接
- **输入校验**：学号、课程号、姓名、分数等合法性校验
- **权限与认证**：管理员、教师、学生多角色权限控制和登录
- **系统日志**：所有关键操作自动记录日志文件
- **单元测试**：各功能模块均有独立测试文件，保证系统健壮性
- **批量数据与性能**：支持大数据量导入、批量处理、模拟学生/课程/成绩
- **良好注释**：每个类、函数、参数均有详细注释，便于二次开发

---

## 编译&运行

1. **编译主程序**
    g++ main.cpp modules\DataImporter.cpp modules\StudentManagementSystem.cpp modules\Student.cpp modules\Course.cpp modules\Score.cpp modules\User.cpp modules\Validator.cpp modules\Logger.cpp modules\Auth.cpp modules\Permission.cpp -o stu_sys -std=c++11 -pthread

    - 若只需部分功能或测试，按需调整编译文件列表。

2. **运行主程序**
    ```sh
    ./stu_sys。exe
    ```

3. **运行模块测试**
    ```sh
    g++ modules/TestStudent.cpp modules/Student.cpp -o test_student && ./test_student
    # 其他模块同理，详见 modules/README.md
    ```

---

## 使用说明

- **首次登录**：系统默认提供用户名/密码：
    - 管理员：admin / admin123
    - 教师：teacher / teacher
    - 学生：stu / stu
- **菜单操作**：根据提示选择各功能，支持增删查改、导入导出、批量处理等
- **数据导入导出**：支持CSV/JSON格式，详见 modules/README_DATA.md
- **日志文件**：所有操作会记录于 system.log
- **权限控制**：不同角色仅可操作授权范围内的功能

---


## 版权与协议

本项目仅用于学习和教学，欢迎二次开发和贡献改进。  
如有问题或建议，请通过 Issues 反馈。

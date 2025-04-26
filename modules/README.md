# 测试说明

本目录包含各功能模块的单元测试代码，每个测试文件均可独立编译运行。如需批量执行测试，可使用如下 shell 脚本：

```sh
g++ TestStudent.cpp Student.cpp -o test_student && ./test_student
g++ TestCourse.cpp Course.cpp -o test_course && ./test_course
g++ TestScore.cpp Score.cpp -o test_score && ./test_score
g++ TestValidator.cpp Validator.cpp -o test_validator && ./test_validator
g++ TestLogger.cpp Logger.cpp -o test_logger && ./test_logger
g++ TestPermission.cpp Permission.cpp -o test_permission && ./test_permission
g++ TestAuth.cpp Auth.cpp User.cpp Permission.cpp -o test_auth && ./test_auth
```

所有测试通过将输出“xxx模块单元测试全部通过！”。

请根据实际项目结构调整依赖文件。
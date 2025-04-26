#pragma once
#include "StudentManagementSystem.h"

// 批量导入学生
void batchImportStudents(StudentManagementSystem& sms, int count);

// 批量导入课程
void batchImportCourses(StudentManagementSystem& sms, int count);

// 随机选课
void randomEnroll(StudentManagementSystem& sms, int studentCount, int courseCount);

// 随机成绩生成
void randomAssignScores(StudentManagementSystem& sms, int studentCount, int courseCount);

// 打印所有学生所有成绩
void printAllScores(const StudentManagementSystem& sms, int studentCount, int courseCount);

// 打印课程平均分
void printCourseAverage(const StudentManagementSystem& sms, int courseCount);

// 打印学生带时间戳
void printStudentWithTimestamp(const Student& stu);
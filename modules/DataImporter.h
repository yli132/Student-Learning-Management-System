#pragma once
#include <string>
#include <map>
#include "Student.h"
#include "Course.h"
#include "Score.h"

/**
 * @brief 数据导入（CSV）
 */
class DataImporter {
public:
    static bool importStudentsFromCSV(const std::string& filename, std::map<std::string, Student>& students);
    static bool importCoursesFromCSV(const std::string& filename, std::map<std::string, Course>& courses);
    static bool importScoresFromCSV(const std::string& filename, std::map<std::string, Score>& scores);
};
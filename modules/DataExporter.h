#pragma once
#include <string>
#include <vector>
#include <map>
#include "Student.h"
#include "Course.h"
#include "Score.h"

/**
 * @brief 数据导出（CSV/JSON）
 */
class DataExporter {
public:
    static bool exportStudentsToCSV(const std::string& filename, const std::map<std::string, Student>& students);
    static bool exportCoursesToCSV(const std::string& filename, const std::map<std::string, Course>& courses);
    static bool exportScoresToCSV(const std::string& filename, const std::map<std::string, Score>& scores);

    static bool exportStudentsToJSON(const std::string& filename, const std::map<std::string, Student>& students);
    static bool exportCoursesToJSON(const std::string& filename, const std::map<std::string, Course>& courses);
    static bool exportScoresToJSON(const std::string& filename, const std::map<std::string, Score>& scores);
};
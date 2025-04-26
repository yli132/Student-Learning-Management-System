#include "DataExporter.h"
#include <fstream>
#include <sstream>

bool DataExporter::exportStudentsToCSV(const std::string& filename, const std::map<std::string, Student>& students) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return false;
    fout << "studentId,name,age,gender,department,address,courses\n";
    for (const auto& pair : students) {
        const auto& s = pair.second;
        fout << s.studentId << "," << s.name << "," << s.age << "," << s.gender << "," << s.department << ",\"";
        for (size_t i = 0; i < s.address.size(); ++i) {
            if (i) fout << ";";
            fout << s.address[i];
        }
        fout << "\",\"";
        size_t cnt = 0;
        for (const auto& cid : s.enrolledCourseIds) {
            if (cnt++) fout << ";";
            fout << cid;
        }
        fout << "\"\n";
    }
    fout.close();
    return true;
}

bool DataExporter::exportCoursesToCSV(const std::string& filename, const std::map<std::string, Course>& courses) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return false;
    fout << "courseId,courseName,teacherName,credit,studentIds\n";
    for (const auto& pair : courses) {
        const auto& c = pair.second;
        fout << c.courseId << "," << c.courseName << "," << c.teacherName << "," << c.credit << ",\"";
        size_t cnt = 0;
        for (const auto& sid : c.studentIds) {
            if (cnt++) fout << ";";
            fout << sid;
        }
        fout << "\"\n";
    }
    fout.close();
    return true;
}

bool DataExporter::exportScoresToCSV(const std::string& filename, const std::map<std::string, Score>& scores) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return false;
    fout << "studentId,courseId,score\n";
    for (const auto& pair : scores) {
        const auto& s = pair.second;
        for (const auto& c : s.courseScores) {
            fout << s.studentId << "," << c.first << "," << c.second << "\n";
        }
    }
    fout.close();
    return true;
}

// 简单JSON导出（无第三方库，手动拼接）
bool DataExporter::exportStudentsToJSON(const std::string& filename, const std::map<std::string, Student>& students) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return false;
    fout << "[\n";
    size_t i = 0;
    for (const auto& pair : students) {
        const auto& s = pair.second;
        fout << "  {\n";
        fout << "    \"studentId\": \"" << s.studentId << "\",\n";
        fout << "    \"name\": \"" << s.name << "\",\n";
        fout << "    \"age\": " << s.age << ",\n";
        fout << "    \"gender\": \"" << s.gender << "\",\n";
        fout << "    \"department\": \"" << s.department << "\",\n";
        fout << "    \"address\": [";
        for (size_t j = 0; j < s.address.size(); ++j) {
            if (j) fout << ", ";
            fout << "\"" << s.address[j] << "\"";
        }
        fout << "],\n";
        fout << "    \"courses\": [";
        size_t cnt = 0;
        for (const auto& cid : s.enrolledCourseIds) {
            if (cnt++) fout << ", ";
            fout << "\"" << cid << "\"";
        }
        fout << "]\n";
        fout << "  }";
        if (++i < students.size()) fout << ",";
        fout << "\n";
    }
    fout << "]\n";
    fout.close();
    return true;
}

bool DataExporter::exportCoursesToJSON(const std::string& filename, const std::map<std::string, Course>& courses) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return false;
    fout << "[\n";
    size_t i = 0;
    for (const auto& pair : courses) {
        const auto& c = pair.second;
        fout << "  {\n";
        fout << "    \"courseId\": \"" << c.courseId << "\",\n";
        fout << "    \"courseName\": \"" << c.courseName << "\",\n";
        fout << "    \"teacherName\": \"" << c.teacherName << "\",\n";
        fout << "    \"credit\": " << c.credit << ",\n";
        fout << "    \"studentIds\": [";
        size_t cnt = 0;
        for (const auto& sid : c.studentIds) {
            if (cnt++) fout << ", ";
            fout << "\"" << sid << "\"";
        }
        fout << "]\n";
        fout << "  }";
        if (++i < courses.size()) fout << ",";
        fout << "\n";
    }
    fout << "]\n";
    fout.close();
    return true;
}

bool DataExporter::exportScoresToJSON(const std::string& filename, const std::map<std::string, Score>& scores) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return false;
    fout << "[\n";
    size_t i = 0;
    for (const auto& pair : scores) {
        const auto& s = pair.second;
        fout << "  {\n";
        fout << "    \"studentId\": \"" << s.studentId << "\",\n";
        fout << "    \"scores\": {";
        size_t cnt = 0;
        for (const auto& sc : s.courseScores) {
            if (cnt++) fout << ", ";
            fout << "\"" << sc.first << "\": " << sc.second;
        }
        fout << "}\n";
        fout << "  }";
        if (++i < scores.size()) fout << ",";
        fout << "\n";
    }
    fout << "]\n";
    fout.close();
    return true;
}
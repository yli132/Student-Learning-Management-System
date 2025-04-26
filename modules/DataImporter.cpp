#include "DataImporter.h"
#include <fstream>
#include <sstream>

bool DataImporter::importStudentsFromCSV(const std::string& filename, std::map<std::string, Student>& students) {
    std::ifstream fin(filename);
    if (!fin.is_open()) return false;
    std::string line, word;
    getline(fin, line); // 跳过表头
    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::vector<std::string> field;
        while (getline(ss, word, ',')) {
            field.push_back(word);
        }
        if (field.size() < 6) continue;
        Student s;
        s.studentId = field[0];
        s.name = field[1];
        s.age = std::stoi(field[2]);
        s.gender = field[3];
        s.department = field[4];
        // 地址
        std::stringstream addrss(field[5]);
        std::string a;
        while (getline(addrss, a, ';')) s.address.push_back(a);
        // 课程
        if (field.size() > 6) {
            std::stringstream cids(field[6]);
            while (getline(cids, a, ';')) s.enrolledCourseIds.insert(a);
        }
        students[s.studentId] = s;
    }
    fin.close();
    return true;
}

bool DataImporter::importCoursesFromCSV(const std::string& filename, std::map<std::string, Course>& courses) {
    std::ifstream fin(filename);
    if (!fin.is_open()) return false;
    std::string line, word;
    getline(fin, line); // 跳过表头
    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::vector<std::string> field;
        while (getline(ss, word, ',')) {
            field.push_back(word);
        }
        if (field.size() < 5) continue;
        Course c;
        c.courseId = field[0];
        c.courseName = field[1];
        c.teacherName = field[2];
        c.credit = std::stoi(field[3]);
        // 选课学生
        std::stringstream sids(field[4]);
        std::string s;
        while (getline(sids, s, ';')) c.studentIds.insert(s);
        courses[c.courseId] = c;
    }
    fin.close();
    return true;
}

bool DataImporter::importScoresFromCSV(const std::string& filename, std::map<std::string, Score>& scores) {
    std::ifstream fin(filename);
    if (!fin.is_open()) return false;
    std::string line, word;
    getline(fin, line); // 跳过表头
    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::vector<std::string> field;
        while (getline(ss, word, ',')) {
            field.push_back(word);
        }
        if (field.size() < 3) continue;
        std::string sid = field[0];
        std::string cid = field[1];
        double sc = std::stod(field[2]);
        if (scores.count(sid) == 0)
            scores[sid] = Score(sid);
        scores[sid].setScore(cid, sc);
    }
    fin.close();
    return true;
}
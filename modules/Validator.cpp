#include "Validator.h"

bool Validator::validateStudentId(const std::string& id) {
    return std::regex_match(id, std::regex("^s[0-9]{4,}$"));
}
bool Validator::validateCourseId(const std::string& id) {
    return std::regex_match(id, std::regex("^c[0-9]{3,}$"));
}
bool Validator::validateName(const std::string& name) {
    return std::regex_match(name, std::regex("^[\u4e00-\u9fa5a-zA-Z ]{2,20}$"));
}
bool Validator::validateAge(int age) {
    return age >= 10 && age <= 100;
}
bool Validator::validateGender(const std::string& gender) {
    return gender == "男" || gender == "女" || gender == "male" || gender == "female";
}
bool Validator::validateScore(double score) {
    return score >= 0 && score <= 100;
}
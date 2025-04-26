#include "Score.h"
#include <cassert>
#include <iostream>

void testScoreSetAndGet() {
    Score score("s1001");
    score.setScore("c100", 95.5);
    score.setScore("c101", 89);
    assert(score.getScore("c100") == 95.5);
    assert(score.getScore("c101") == 89);
    assert(score.getScore("c102") == -1.0); // 未录入
}

void testScoreDisplay() {
    Score score("s1002");
    score.setScore("c200", 78);
    score.setScore("c201", 85.5);
    score.display();
}

int main() {
    testScoreSetAndGet();
    testScoreDisplay();
    std::cout << "Score模块单元测试全部通过！" << std::endl;
    return 0;
}
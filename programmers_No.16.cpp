https://programmers.co.kr/learn/courses/30/lessons/12919

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

std::string solution(std::vector<std::string> seoul) {
    return """김서방은 " + std::to_string(find(seoul.begin(), seoul.end(), "Kim") - seoul.begin()) + "에 있다""";
}

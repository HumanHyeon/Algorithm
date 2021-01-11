https://programmers.co.kr/learn/courses/30/lessons/12925

#include <string>
using namespace std;

int solution(string s) {
    return stoi(s.substr(0, s.size()));
}

https://programmers.co.kr/learn/courses/30/lessons/12917

#include <algorithm>

std::string solution(std::string s) {
    std::sort(s.rbegin(), s.rend());
    return s;
}

//sort(s.begin(), s.end(), greater<char>());

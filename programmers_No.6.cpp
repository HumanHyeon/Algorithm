https://programmers.co.kr/learn/courses/30/lessons/12939

#include <sstream>
using namespace std;

string solution(string s) {
    int min = INT32_MAX, max = INT32_MIN;

    stringstream ss(s);
    int num;
    while (ss >> num) {
        if (min > num) min = num;
        if (max < num) max = num;
    }
    if (max == INT_FAST32_MIN)   max = min;
 
    return to_string(min) + " " + to_string(max);
}

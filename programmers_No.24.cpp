https://programmers.co.kr/learn/courses/30/lessons/12935

#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) return { -1 };
    arr.erase(min_element(arr.begin(), arr.end()));
    return arr;
}

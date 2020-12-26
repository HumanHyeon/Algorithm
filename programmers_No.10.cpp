https://programmers.co.kr/learn/courses/30/lessons/43165

#include <vector>
using namespace std;

int answer = 0;

bool promising(vector<int>& numbers, int total, int index, int target) {
    int remainder = 0;
    for (int i = index; i < numbers.size(); i++) remainder += numbers[i];

    if (total < target) {
        if (total + remainder < target)  return false;
        return true;
    }
    else if (total > target) {
        if (total - remainder > target)  return false;
        return true;
    }

    return true;
}

void dfs(vector<int>& numbers, int target, int index = 0, int total = 0) {
    if (index == numbers.size()) {
        if (total == target) answer++;
        return;
    }
    if (promising(numbers, total, index, target)) {
        dfs(numbers, target, index + 1, total + numbers[index]);
        dfs(numbers, target, index + 1, total - numbers[index]);
    }
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target);
    return answer;
}

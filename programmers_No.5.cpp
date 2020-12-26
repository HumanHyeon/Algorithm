https://programmers.co.kr/learn/courses/30/lessons/12924

#include <vector>
using namespace std;

int solution(int n) {
    int answer = 1;

    for (int start = 0; start <= n / 2; start++) {
        int sum = 0;
        for (int add = start; sum <= n; add++, sum += add)
            if (sum == n)   answer++;
    }

    return answer;
}

//In cmath headerfile
//ceil() : 올림 함수
// 

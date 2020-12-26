https://programmers.co.kr/learn/courses/30/lessons/12911

#include <bitset>
#include <string>
using namespace std;

int solution(int n) {
    int answer = 0;
    string num = bitset<20>(n).to_string();
    int lastOne, continuousOne = -1, mul = 1;

    for (lastOne = num.size() - 1; lastOne >= 0; lastOne--) if (num[lastOne] == '1') break;
    for (lastOne; num[lastOne] == '1'; lastOne--) {
        continuousOne++;
        num[lastOne] = '0';
    }
    num[lastOne] = '1';
    for (int i = num.size() - 1; continuousOne > 0; continuousOne--, i--) num[i] = '1';
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] == '1')    answer += mul;
        mul *= 2;
    }
    return answer;
}

//다른 풀이 : 1의 비트 수를 세고 answer에 n을 삽입 후 answer++하며 1의 비트 수 같을 때 까지 증가

//interesting Code
//#include <bitset>
//using namespace std;
//
//int solution(int n) {
//    int num = bitset<20>(n).count();
//
//    while (bitset<20>(++n).count() != num);
//    return n;
//}

https://programmers.co.kr/learn/courses/30/lessons/12921

#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> er;
    er.push_back(-1);
    for (int i = 2; i <= n; i++) er.push_back(i);

    for (int i = 2; i * i <= n; i++) {
        if (er[i - 1] == -1) continue;
        for (int j = 2 * i; j <= n; j += i)
            er[j - 1] = -1;
    }

    for (auto tmp : er)  if (tmp != -1)  answer++;
    return answer;
}

//#include <set>
//using namespace std;
//
//int solution(int n) {
//    set<int> eratosthenes;
//    for (int i = 2; i <= n; i++) eratosthenes.insert(i);
//    for (int i = 2; i * i <= n; i++) 
//        for (int j = 2 * i; j <= n; j += i) 
//            eratosthenes.erase(j);
//    return eratosthenes.size();
//}

#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start = 0;
    for (int i = 0; i < number.size() - k; i++) {
        string stringList = number.substr(start, i + k - start + 1);
        answer += *max_element(stringList.begin(), stringList.end());
        start += stringList.find(*max_element(stringList.begin(), stringList.end())) + 1;
    }
    return answer;
}

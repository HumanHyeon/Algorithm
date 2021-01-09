https://programmers.co.kr/learn/courses/30/lessons/42746

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringNumbers;

    if (*max_element(numbers.begin(), numbers.end()) == 0)   return "0";
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        string input = to_string(*iter) + to_string(*iter) + to_string(*iter) + to_string(*iter);
        stringNumbers.push_back(input);
    }
    sort(stringNumbers.rbegin(), stringNumbers.rend());
    for (auto inputAnswer : stringNumbers) 
        answer += inputAnswer.substr(0, inputAnswer.size() / 4);

    return answer;
}

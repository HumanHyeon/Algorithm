https://programmers.co.kr/learn/courses/30/lessons/12910

#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
        if(arr[i] < divisor)   continue;
        else{
            if(!(arr[i] % divisor)) answer.push_back(arr[i]);
        }
    
    if(answer.empty())  return { -1 };
    return answer;
}

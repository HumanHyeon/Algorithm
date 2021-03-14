https://programmers.co.kr/learn/courses/30/lessons/12944

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto fetch : arr) answer += fetch;   
    return answer / arr.size();
}


impressive 
double answer = accumulate(arr.begin(), arr.end(), 0);

if want product
std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

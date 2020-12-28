#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> element, tmp;
    multiset<char> eraseList;

    for (int i = 0; i < number.size(); i++)  element.push_back(number[i]);
    
    tmp = element;
    sort(tmp.begin(), tmp.end());
    
    for (int i = 0; i < k; i++)  eraseList.insert(tmp[i]);
    
    for (int i = 0; i < number.size() && !eraseList.empty(); ) 
        if (eraseList.find(element[i]) != eraseList.end()) {
            eraseList.erase(eraseList.find(element[i]));
            element.erase(element.begin() + i);
        }
        else  i++;

    for (int i = 0; i < element.size(); i++) answer += element[i];

    return answer;
}

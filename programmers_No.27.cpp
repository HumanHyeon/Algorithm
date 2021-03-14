https://programmers.co.kr/learn/courses/30/lessons/12930

#include <sstream>
#include <vector>
using namespace std;

string change(string s) {
    for (int i = 0; i < s.size(); i++)
        i & 1 ? s[i] = tolower(s[i]) : s[i] = toupper(s[i]);
    return s;
}

string solution(string s) {
    vector<string> tmp;
    stringstream ss(s);
    string fetch, answer = "";
    while (ss >> fetch) tmp.push_back(change(fetch));

    bool check = false;
    int index = 0;
    for (int i = 0; i < s.size(); i++) 
        if (s[i] == ' ') answer += " ", check = false;
        else 
            if (!check) 
                answer += tmp[index++], check = true;
        
            
    return answer;
}

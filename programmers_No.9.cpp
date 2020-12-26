https://programmers.co.kr/learn/courses/30/lessons/12951

#include <queue>
#include <sstream>
using namespace std;

string solution(string s) {
    queue<int> indexTable;
    stringstream ss(s);
    string tmp;
    bool flag = false;

    for (int i = 0; i < s.size(); i++) 
        if (flag) {
            if (s[i] == ' ')
                flag = false;
        }
        else {
            if (s[i] != ' ') {
                flag = true;
                indexTable.push(i);
            }
        }
    while (ss >> tmp) {
        tmp[0] = toupper(tmp[0]);
        for (int i = 1; i < tmp.size(); i++) tmp[i] = tolower(tmp[i]);
        for (int i = indexTable.front(), count = 0; count < tmp.size(); i++, count++) s[i] = tmp[count];
        indexTable.pop();
    }
    return s;
}

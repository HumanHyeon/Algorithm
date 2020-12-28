#include <iostream>
#include <string>
#include <vector>
using namespace std;

string maxNum;
int c = 0;

bool cmpStr(string challenger) {
    if (maxNum == "-1")    return true;
    for (int i = 0; i < challenger.size(); i++) {
        if (maxNum[i] > challenger[i]) return false;
        else return true;
    }
}

bool promising(int makeCount, string accumulate) {
    if (maxNum == "-1")    return true;
    for (int i = 0; i < makeCount; i++)  accumulate += "9";
    if (cmpStr(accumulate))  return true;
    else return false;
}

void dfs(string number, int makeCount, string accumulate) {
    if (makeCount == 0) {
        if (cmpStr(accumulate))   maxNum = accumulate;
        return;
    }
    c++;

    for (int i = 0; i < number.size(); i++) {
        if(promising(makeCount, accumulate))
            dfs(number.substr(i + 1, number.size()), makeCount - 1, accumulate + number[i]);
    }
}

string solution(string number, int k) {
    maxNum = "-1";

    for (int i = 0; i < number.size() - 1; i++) {
        string accumulate = "";
        accumulate += number[i];
        dfs(number.substr(i + 1, number.size()), number.size() - k - 1, accumulate);
    }

    return maxNum;
}

https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
using namespace std;

string largeCombination = "-1";
vector<int> numbers;
int AnswerSize;

bool promising(int index, string accumulate) {
    if (largeCombination == "-1") return true;
    for (int i = 0; i < AnswerSize - accumulate.size(); i++)    accumulate += "9";
    if (largeCombination.compare(accumulate) == 1)  return false;
    return true;
}

void dfs(vector<bool> selected, int index, string accumulate, int count = 1) {
    if (count == selected.size()) {
        if (accumulate.compare(largeCombination) == 1)   largeCombination = accumulate;
        return;
    }
    for (int i = 0; i < selected.size(); i++) {
        if (promising(index, accumulate)) {
            if (selected[i]) continue;
            selected[i] = true;
            dfs(selected, index + 1, accumulate + to_string(numbers[i]), count + 1);
            selected[i] = false;
        }
    }
}

string solution(vector<int> n) {
    vector<bool> selected(n.size());
    string sizeCheck = "";
    numbers = n;

    for (int i = 0; i < n.size(); i++) sizeCheck += to_string(n[i]);
    AnswerSize = sizeCheck.size();

    for (int i = 0; i < n.size(); i++) {
        selected[i] = true;
        dfs(selected, i, to_string(numbers[i]));
        selected[i] = false;
    }
    return largeCombination;
}

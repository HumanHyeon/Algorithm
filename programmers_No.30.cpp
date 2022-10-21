#include <iostream>
#include <string>
#include <vector>
using namespace std;

string _target;
vector<string> _words;

int answer;
bool visited[51] = { false, };

bool isValid(string src, string dest) {
    bool hasChance = true;

    for (int i = 0; i < src.size(); i++) {
        char s = src[i], d = dest[i];

        if (s != d) {
            if (!hasChance) return (false);
            hasChance = false;
        }
    }

    return (true);
}

void dfs(string str, int num = 0) {
    if (str == _target) {
        answer = min(answer, num);
        return;
    }

    for (int i = 0; i < _words.size(); i++) {
        if (!visited[i] && isValid(str, _words[i])) {
            visited[i] = true;
            dfs(_words[i], num + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    answer = 987654321;
    _target = target;
    _words = words;

    dfs(begin);

    return (answer == 987654321 ? 0 : answer);
}

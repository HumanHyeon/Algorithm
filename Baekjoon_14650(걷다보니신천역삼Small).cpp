https://www.acmicpc.net/problem/14650

#include <iostream>
using namespace std;

int answer;
int N;

void dfs(string num, int depth) {
	if (depth == N) {
		if (stoi(num) % 3 == 0)	answer++;
		return;
	}
	dfs(num + "0", depth + 1);
	dfs(num + "1", depth + 1);
	dfs(num + "2", depth + 1);
}

int solution() {
	dfs("1", 1);
	dfs("2", 1);
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	cout << solution() << endl;
}

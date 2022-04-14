https://www.acmicpc.net/problem/9663

#include <iostream>
using namespace std;

int N;
int board[16];
int answer = 0;

bool promising(int position) {
	for (int i = 0; i < position; i++) {
		if (board[position] == board[i] || position - i == abs(board[position] - board[i]))
			return (false);
	}
	return (true);
}

void dfs(int lastColumn) {
	if (lastColumn == N - 1) {
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) {
		board[lastColumn + 1] = i;
		if (promising(lastColumn + 1)) 
			dfs(lastColumn + 1);
	}
}

int solution() {
	for (int i = 0; i < N; i++) {
		board[0] = i;
		dfs(0);
	}

	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	cout << solution() << endl;
}

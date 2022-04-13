https://www.acmicpc.net/problem/17281

#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int N;
int inning[50][9];
int answer;

bool base[3];

int hits(int num) {
	int score = 0;

	if (num == 4) {
		for (int i = 0; i < 3; i++) {
			if (base[i])	score++;
			base[i] = false;
		}
		score++;
	}
	else {
		for (int cycle = 0; cycle < num; cycle++) {

			if (base[2])	score++;
			base[2] = base[1];
			base[1] = base[0];
			if (cycle == 0)	base[0] = true;
			else			base[0] = false;
		}
	}

	return (score);
}

int run(vector<int>& order) {
	int score = 0;
	int playerIndex = 0;

	for (int i = 0; i < N; i++) {
		int outCount = 3;
		bool nextInnging = false;

		memset(base, 0, sizeof(base));
		while (true) {
			for (int pi = playerIndex; pi < 9; pi++) {
				int action = inning[i][order[pi] - 1];

				if (action == 0)	--outCount;
				else	score += hits(action);

				if (outCount == 0) {
					playerIndex = (pi + 1 == 9 ? 0 : pi + 1);
					nextInnging = true;
					break;
				}
			}
			if (nextInnging)	break;
			else playerIndex = 0;
		}
	}
	return (score);
}

int solution() {
	vector<int> order = { 2, 3, 4, 5, 6, 7, 8, 9 };

	do {
		vector<int> t_order;
		for (int i = 0; i < 9; i++) {
			if (i < 3)			t_order.emplace_back(order[i]);
			else if (i == 3)	t_order.emplace_back(1);
			else if (i > 3)		t_order.emplace_back(order[i - 1]);
		}
		answer = max(answer, run(t_order));
	} while (next_permutation(order.begin(), order.end()));
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 9; j++)
			cin >> inning[i][j];
	cout << solution() << endl;
}

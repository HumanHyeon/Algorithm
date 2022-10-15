#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define TWELVE 0
#define RIGHT 2
#define LEFT 6
#define CLOCKWISE 1
#define COUNTER_CLOCKWISE -1
#define S_POLE 1
#define N_POLE 0
#define GO_RIGHT 1
#define GO_LEFT -1

typedef pair<int, int> pii;

int gear[4][8];
int K;
vector<pii> orders;
int visited[4];
int answer;

int computeScore() {
	int score = 0;

	for (int i = 0; i < 4; i++) {
		int state = gear[i][TWELVE];

		if (state == N_POLE) continue;
		score += pow(2, i);
	}
	
	return (score);
}

void rotate(int id, int flag) {
	int tmp;

	if (flag == CLOCKWISE) {
		tmp = gear[id][7];

		for (int i = 7; i > 0; i--) 
			gear[id][i] = gear[id][i - 1];
		gear[id][0] = tmp;
	}
	else {
		tmp = gear[id][0];

		for (int i = 0; i < 7; i++)
			gear[id][i] = gear[id][i + 1];
		gear[id][7] = tmp;
	}
}

void dfs(int id, int flag) {
	int now_right = gear[id][RIGHT], now_left = gear[id][LEFT];
	int counterFlag = (flag == CLOCKWISE ? COUNTER_CLOCKWISE : CLOCKWISE);
	int rightSide_left = -99, leftSide_right = -99;
	
	rotate(id, flag);

	if (id == 3) {
		leftSide_right = gear[id - 1][RIGHT];

		if (!visited[id - 1] && now_left != leftSide_right) {
			visited[id - 1] = true;
			dfs(id - 1, counterFlag);
		}
	}
	else if (id == 0) {
		rightSide_left = gear[id + 1][LEFT];

		if (!visited[id + 1] && now_right != rightSide_left) {
			visited[id + 1] = true;
			dfs(id + 1, counterFlag);
		}
	}
	else {
		rightSide_left = gear[id + 1][LEFT];
		leftSide_right = gear[id - 1][RIGHT];

		if (!visited[id + 1] && now_right != rightSide_left) {
			visited[id + 1] = true;
			dfs(id + 1, counterFlag);
		}
		if (!visited[id - 1] && now_left != leftSide_right) {
			visited[id - 1] = true;
			dfs(id - 1, counterFlag);
		}
	}
}

void solution() {
	for (auto order : orders) {
		int id = order.first, flag = order.second;
		visited[0] = visited[1] = visited[2] = visited[3] = false;

		visited[id] = true;
		dfs(id, flag);
	}
	answer = computeScore();
}

void init() {
	for (int i = 0; i < 4; i++) {
		string input;

		cin >> input;
		for (int j = 0; j < 8; j++) {
			int pole = input[j] - '0';

			gear[i][j] = pole;
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int id, flag;

		cin >> id >> flag;

		orders.push_back(make_pair(id - 1, flag));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	init();
	solution();

	cout << answer;
}

#include <iostream>
#include <algorithm>
using namespace std;

int answer = 987654321;

const int SIZE = 10;
int b[SIZE][SIZE];

int cnt[] = { -1, 5, 5, 5, 5, 5 };

bool isFin() {
	for (int i = 0; i < SIZE; i++) 
		for (int j = 0; j < SIZE; j++) 
			if (b[i][j] == 1)	return (false);
	return (true);
}

bool isValid(int y, int x, int size) {
	if (y + size - 1 >= SIZE || x + size - 1 >= SIZE) {
		return (false);
	}
	for (int i = 0; i < size; i++) {
		int ny = y + i;
		
		for (int j = 0; j < size; j++) {
			int nx = x + j;

			if (b[ny][nx] == 0)	return (false);
		}
	}
	return (true);
}

void fill(int y, int x, int size) {
	for (int i = 0; i < size; i++) {
		int ny = y + i;

		for (int j = 0; j < size; j++) {
			int nx = x + j;

			b[ny][nx] = 0;
		}
	}
}

void vacate(int y, int x, int size) {
	for (int i = 0; i < size; i++) {
		int ny = y + i;

		for (int j = 0; j < size; j++) {
			int nx = x + j;

			b[ny][nx] = 1;
		}
	}
}

void dfs(int y, int x) {
	int used = (5 - cnt[1]) + (5 - cnt[2]) + (5 - cnt[3]) + (5 - cnt[4]) + (5 - cnt[5]);
	
	if (used >= answer)	return;	//백트래킹

	if (y == SIZE && x == 0) {	//기저사례
		if (!isFin())	return;
		answer = min(answer, used);
		return;
	}
	else if (used == 25) {	//다 썻음
		if (!isFin())	return;
		answer = min(answer, used);
		return;
	}

	if (b[y][x] == 0) {
		if (x == SIZE - 1)	dfs(y + 1, 0);
		else				dfs(y, x + 1);
	}
	else {
		for (int i = 5; i >= 1; i--) {
			if (cnt[i] == 0)	continue;

			if (isValid(y, x, i)) {
				cnt[i] = cnt[i] - 1;
				fill(y, x, i);


				if (x == SIZE - 1)	dfs(y + 1, 0);
				else				dfs(y, x + 1);
				
				vacate(y, x, i);
				cnt[i] = cnt[i] + 1;
			}
		}
	}
}

void solution() {
	dfs(0, 0);
}

void init() {
	for (int i = 0; i < SIZE; i++) 
		for (int j = 0; j < SIZE; j++) 
			cin >> b[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	init();
	solution();
	
	cout << (answer == 987654321 ? -1 : answer) << endl;
}

https://www.acmicpc.net/problem/18430

#include <iostream>
using namespace std;

int map[5][5]; 
int N, M;
int answer;
int cache[5][5];

int bommerang_y[][3] = {
	{ 0, 0, 1 },
	{ 0, 0, -1 },
	{ -1, 0, 0 },
	{ 1, 0, 0 }
};
int bommerang_x[][3] = {
	{ -1, 0, 0 },
	{ -1, 0, 0 },
	{ 0, 0, 1 },
	{ 0, 0, 1 }
};

bool is_valid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M)		return (false);
	if (cache[y][x] != 0)	return (false);
	return (true);
}

int calc_strength(int y, int x, int type) {
	int strength = 0;
	strength += (map[y][x] * 2);
	strength += map[y + bommerang_y[type][0]][x + bommerang_x[type][0]];
	strength += map[y + bommerang_y[type][2]][x + bommerang_x[type][2]];
	return (strength);
}


void makingBommerang(int startY, int startX, int mark = 1, int accumulate = 0) {
	if (startY == N) {
		answer = (answer < accumulate ? accumulate : answer);
		return;
	}

	if (cache[startY][startX] == 0) {
		for (int type = 0; type < 4; type++) {
			bool check = true;

			for (int index = 0; index < 3; index++) {
				int ny = startY + bommerang_y[type][index];
				int nx = startX + bommerang_x[type][index];

				if (!is_valid(ny, nx)) {
					check = false;
					break;
				}
			}

			if (check) {
				int strength = calc_strength(startY, startX, type);
				
				for (int index = 0; index < 3; index++) {
					int ny = startY + bommerang_y[type][index];
					int nx = startX + bommerang_x[type][index];
					cache[ny][nx] = mark;
				}
				if (startX + 1 == M)	makingBommerang(startY + 1, 0, mark + 1, accumulate + strength);
				else					makingBommerang(startY, startX + 1, mark + 1, accumulate + strength);
				for (int index = 0; index < 3; index++) {
					int ny = startY + bommerang_y[type][index];
					int nx = startX + bommerang_x[type][index];
					cache[ny][nx] = 0;
				}
			}
		}
	}
	if (startX + 1 == M)	makingBommerang(startY + 1, 0, mark, accumulate);
	else					makingBommerang(startY, startX + 1, mark, accumulate);
}

int solution() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			makingBommerang(y, x);
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	cout << solution() << endl;
}

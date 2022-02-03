//https://www.acmicpc.net/problem/2589

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 50;
const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { -1, 1, 0, 0 };

int column, row;

char map[MAX][MAX];
int cache[MAX][MAX];

queue<pair<int, int>> table;

int bfs(int y, int x) {
	int answer = -1;

	table.push(make_pair(y, x));
	cache[y][x] = 1;

	while (!table.empty()) {
		int nowY = table.front().first;
		int nowX = table.front().second;
		
		table.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= column || nextX >= row || map[nextY][nextX] != 'L')
				continue;
			if (cache[nextY][nextX] == 0) {
				cache[nextY][nextX] = cache[nowY][nowX] + 1;
				table.push(make_pair(nextY, nextX));
				
				if (cache[nextY][nextX] > answer)
					answer = cache[nextY][nextX];
			}
		}
	}
	return (answer - 1);
}

int solution() {
	int answer = -1;

	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++)
			if (map[i][j] == 'L') {
				int tmp;

				tmp = bfs(i, j);
				if (tmp > answer)
					answer = tmp;
				memset(cache, 0, sizeof(cache));
			}

	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	cin >> column >> row;

	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++)
			cin >> map[i][j];
	cout << solution();
}

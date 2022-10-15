#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N, L, R;
int a[51][51];
int answer;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int visited[51][51];

typedef pair<int, int> pii;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)	return (false);
	return (true);
}

bool canCombine(int std, int cmp) {
	int diff = abs(std - cmp);

	if (L <= diff && diff <= R)	return (true);
	return (false);
}

bool bfs(int nowY, int nowX) {
	bool didMove = false;
	queue<pii> q, logs;
	int accumulate = 0, cnt = 0, population;

	visited[nowY][nowX] = true;
	q.push(make_pair(nowY, nowX));
	logs.push(make_pair(nowY, nowX));
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		int std = a[y][x];
		q.pop();

		accumulate += std;
		cnt++;

		for (int flag = 0; flag < 4; flag++) {
			int ny = y + dy[flag], nx = x + dx[flag];

			if (isValid(ny, nx)) {
				int cmp = a[ny][nx];

				if (visited[ny][nx] ||!canCombine(std, cmp))	continue;

				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				logs.push(make_pair(ny, nx));

				didMove = true;
			}
		}
	}

	population = accumulate / cnt;
	while (!logs.empty()) {
		int y = logs.front().first, x = logs.front().second;
		logs.pop();

		a[y][x] = population;
	}

	return (didMove);
}

void solution() {
	while (true) {
		bool didMove = false;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				visited[y][x] = false;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				if (!visited[y][x]) {
					bool result = bfs(y, x);

					if (result)
						didMove = true;
				}			

		if (!didMove)	break;
		answer++;
	}
}

void init() {
	cin >> N >> L >> R;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> a[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	init();
	solution();

	cout << answer;
}

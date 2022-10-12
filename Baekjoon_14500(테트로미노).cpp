#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int b[501][501];
int answer = -1;

vector<pair<int, int>> v(4);
bool visited[501][501] = { {false, }, };
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int exceptY[] = { 0, -1, 1, 0, 0 };
int exceptX[] = { -1, 0, 0, 1, 0 };

bool isValidPos(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M)	return (false);
	if (visited[y][x])	return (false);
	return (true);
}

void run(int y, int x, int cnt = 0) {
	if (cnt == 4) {
		int accumulate = 0;
		
		for (int i = 0; i < 4; i++) {
			int py = v[i].first;
			int px = v[i].second;

			accumulate += b[py][px];
		}
		answer = max(answer, accumulate);
		
		return;
	}

	for (int flag = 0; flag < 4; flag++) {
		int ny = y + dy[flag];
		int nx = x + dx[flag];

		if (isValidPos(ny, nx)) {
			v[cnt] = make_pair(ny, nx);
			visited[ny][nx] = true;
			run(ny, nx, cnt + 1);
			visited[ny][nx] = false;
		}
	}
}

void run_except(int y, int x) {
	for (int kinds = 0; kinds < 4; kinds++) {
		int accumulate = 0;
		bool valid = true;

		for (int flag = 0; flag < 5; flag++) {
			if (kinds == flag)	continue;

			int ny = y + exceptY[flag];
			int nx = x + exceptX[flag];

			if (!isValidPos(ny, nx)) {
				valid = false;
				break;
			}
			accumulate += b[ny][nx];
		}
		if (valid)	answer = max(answer, accumulate);
	}
}

void solution() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			run(y, x);
			run_except(y, x);
		}
}

void init() {
	cin >> N >> M;

	for (int y = 0; y < N; y++) 
		for (int x = 0; x < M; x++)
			cin >> b[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	init();
	solution();
	cout << answer;
}

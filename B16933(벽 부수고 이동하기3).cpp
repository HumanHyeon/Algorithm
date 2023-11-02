#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define DAY 0
#define NIGHT 1

typedef pair<int, int> pii;
typedef struct {
	int y;
	int x;
	int cnt;
	int chance;
	int status;
} Pos;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int N, M, K;
bool visited[1001][1001][11];
int board[1001][1001];

int answer = -1;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M)
		return (false);
	return (true);
}

void solution() {
	queue<Pos> q;
	Pos p;

	p.y = 0;
	p.x = 0;
	p.cnt = 1;
	p.chance = K;
	p.status = DAY;
	q.push(p);
	visited[0][0][K] = true;
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int chance = q.front().chance;
		int status = q.front().status;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			answer = cnt;
			break;
		}

		for (int flag = 0; flag < 4; ++flag) {
			int ny = y + dy[flag];
			int nx = x + dx[flag];
			
			if (!isValid(ny, nx)) continue;
			if (visited[ny][nx][chance])	continue;

			if (board[ny][nx] == 0) {
				p.y = ny;
				p.x = nx;
				p.cnt = cnt + 1;
				p.chance = chance;
				if (status == DAY)
					p.status = NIGHT;
				else
					p.status = DAY;
				
				q.push(p);
				visited[ny][nx][chance] = true;
			}
			else {	//WALL
				if (chance == 0)	continue;

				if (status == DAY) {
					p.y = ny;
					p.x = nx;
					p.cnt = cnt + 1;
					p.chance = chance - 1;
					p.status = NIGHT;

					q.push(p);
					visited[ny][nx][chance] = true;
				}
				else {
					p.y = y;
					p.x = x;
					p.cnt = cnt + 1;
					p.chance = chance;
					p.status = DAY;
					
					q.push(p);
				}
			}
		}

	}
}

void input() {
	cin >> N >> M >> K;

	for (int y = 0; y < N; ++y) {
		string s;
		cin >> s;

		for (int x = 0; x < M; ++x) {
			if (s[x] == '0')
				board[y][x] = 0;
			else
				board[y][x] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	input();
	solution();

	cout << answer;
}

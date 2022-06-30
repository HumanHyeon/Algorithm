https://www.acmicpc.net/problem/14503

#include <iostream>
#include <vector>
using namespace std;

#define CHFLAG(N) (((N) != 0? (N) - 1 : (3)))
#define CHBACK(N) (((N) + 2) % 4)

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

const int FIN = -1;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int N, M;
int y, x, flag;
int MAP[51][51];
int answer;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M)	return (false);
	else if (MAP[y][x] == FIN || MAP[y][x] == 1)	return (false);
	return (true);
}

void clean() {
	if (MAP[y][x] != FIN) {
		answer++;
		MAP[y][x] = FIN;
	}
}

bool turnAndCheck() {
	int ny, nx;

	flag = CHFLAG(flag);
	ny = y + dy[flag];
	nx = x + dx[flag];

	return (isValid(ny, nx));
}

void solution() {
	int cycle = 0;

	while (true) {
		if (cycle == 4) {
			int back = CHBACK(flag);
			int ny = y + dy[back], nx = x + dx[back];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	break;
			if (MAP[ny][nx] == 1)	break;

			cycle = 0;
			y = ny;
			x = nx;
		}

		//1. 현재 위치를 청소
		if (cycle == 0)	clean();
	
		//2.
		if (turnAndCheck()) {
			cycle = 0;
			y += dy[flag];
			x += dx[flag];
		}
		else	cycle++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M;
	cin >> y >> x >> flag;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			cin >> MAP[i][j];

	solution();
	cout << answer << endl;
}

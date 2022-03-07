https://www.acmicpc.net/problem/3190

#include <iostream>
#include <memory.h>
using namespace std;

#define CHFLAG(NOW, CMD) ((CMD) == 'L' ? ((NOW) - 1 < 0 ? 3 : (NOW) - 1) : ((NOW) + 1 > 3 ? 0 : (NOW) + 1))

int MAP[101][101];
char zig[10001];

int main() {
	ios_base::sync_with_stdio(false);	cout.tie(NULL);	cin.tie(NULL);

	int N, K, L, time = 1;
	int flag = 1, headY = 0, headX = 0, tailY = 0, tailX = 0;
	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 };
	
	cin >> N >> K;
	for (int i = 0, Y, X; i < K; i++) {
		cin >> Y >> X;
		MAP[Y - 1][X - 1] = -1;
	}	
	MAP[0][0] = time;

	cin >> L;
	memset(zig, ' ', sizeof(zig));
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		zig[X] = C;
	}

	while (true) {
		int ny = headY + dy[flag], nx = headX + dx[flag];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)	break;
		if (MAP[ny][nx] > 0) break;

		time++;
		headY = ny;
		headX = nx;
		if (MAP[ny][nx] == -1)	MAP[ny][nx] = time;
		else {
			MAP[ny][nx] = time;

			for (int direct = 0; direct < 4; direct++) {
				int cmpY = tailY + dy[direct], cmpX = tailX + dx[direct];

				if (cmpY < 0 || cmpX < 0 || cmpY >= N || cmpX >= N)	continue;
				if (MAP[cmpY][cmpX] == (MAP[tailY][tailX] + 1)) {
					MAP[tailY][tailX] = 0;
					tailY = cmpY;
					tailX = cmpX;
					break;
				}
			}
		}
		if (zig[time - 1] != ' ')
			flag = CHFLAG(flag, zig[time - 1]);
	}

	cout << time << endl;
}

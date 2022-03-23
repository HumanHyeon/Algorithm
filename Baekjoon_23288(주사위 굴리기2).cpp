https://www.acmicpc.net/problem/23288

#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int map[21][21];
int answer;

int dice[6];	//2 4 1 3 5 6	윗면: index2		아랫면: index5
static const int dy[] = { 1, -1, 0, 0 };
static const int dx[] = { 0, 0, 1, -1 };
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

void diceRoll(int cmd) {
	int tmp;

	if (cmd == EAST) {	//EAST
		tmp = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	else if (cmd == WEST) {	//WEST
		tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = tmp;
	}
	else if (cmd == NORTH) {	//NORTH
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[5];
		dice[5] = tmp;
	}
	else {	//SOUTH
		tmp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = tmp;
	}
}

int reverseFlag(int flag) {
	if (flag == NORTH)	return (WEST);
	else if (flag == SOUTH) return (NORTH);
	else if (flag == EAST) return (WEST);
	else return (EAST);
}

int changeFlag(int flag, int diff) {
	if (diff < 0) {	//LEFT
		if (flag == NORTH)	return WEST;
		else if (flag == EAST) return NORTH;
		else if (flag == SOUTH) return EAST;
		else return SOUTH;
	}
	else if (diff > 0) {	//RIGHT
		if (flag == NORTH)	return EAST;
		else if (flag == EAST) return SOUTH;
		else if (flag == SOUTH) return WEST;
		else return NORTH;
	}
	else
		return (flag);
}

int calcScore(int y, int x) {
	queue<pair<int, int>> q;
	bool visited[21][21] = { {false, }, };
	int std = map[y][x], cnt = 1;

	memset(visited, false, sizeof(visited));

	q.push(make_pair(y, x));
	visited[y][x] = true;
	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int direction = 0; direction < 4; direction++) {
			int ny = nowY + dy[direction];
			int nx = nowX + dx[direction];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
			if (!visited[ny][nx] && map[ny][nx] == std) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				cnt++;
			}
		}
	}
	return (std * cnt);
}

int solution() {
	int diceY = 0, diceX = 0, flag = EAST;

	for (int cycle = 0; cycle < K; cycle++) {
		int ny = diceY + dy[flag];
		int nx = diceX + dx[flag];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
			flag = reverseFlag(flag);
			ny = diceY + dy[flag];
			nx = diceX + dx[flag];
		}

		diceRoll(flag);
		answer += calcScore(ny, nx);
		flag = changeFlag(flag, (dice[5] - map[ny][nx]));
		diceY = ny, diceX = nx;
	}

	return (answer);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	cout << solution() << endl;
}

https://www.acmicpc.net/problem/14499

#include <iostream>
#include <vector>
using namespace std;

int MAP[21][21];
int N, M, diceX, diceY, K;
vector<int> commands;
int dice[6];	//2 4 1 3 5 6	윗면: index2		아랫면: index5

bool is_valid(int cmd) {
	static int dx[] = { -100, 0, 0, -1, 1 };
	static int dy[] = { -100, 1, -1, 0, 0 };
	int ny = diceY + dy[cmd], nx = diceX + dx[cmd];
	if (ny < 0 || nx < 0 || ny >= M || nx >= N)
		return (false);
	return (true);
}

void diceRoll(int cmd) {
	int tmp;

	if (cmd == 1) {	//EAST
		tmp = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
		diceY++;
	}
	else if (cmd == 2) {	//WEST
		tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = tmp;
		diceY--;
	}
	else if (cmd == 3) {	//NORTH
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[5];
		dice[5] = tmp;
		diceX--;
	}
	else {	//SOUTH
		tmp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = tmp;
		diceX++;
	}
}

void solution() {
	for (vector<int>::iterator iter = commands.begin(); iter != commands.end(); iter++) {
		if (!is_valid(*iter))	continue;
		diceRoll(*iter);
		if (MAP[diceX][diceY] == 0)	MAP[diceX][diceY] = dice[5];
		else	dice[5] = MAP[diceX][diceY], MAP[diceX][diceY] = 0;
		cout << dice[2] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cout.tie(NULL);	cin.tie(NULL);

	cin >> N >> M >> diceX >> diceY >> K;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];
	
	for (int i = 0, cmd; i < K; i++) {
		cin >> cmd;
		commands.push_back(cmd);
	}

	solution();
}

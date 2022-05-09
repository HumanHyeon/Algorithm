https://www.acmicpc.net/problem/12100

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

vector<vector<int>> board;
int N;
int answer;

int findLagreNum(vector<vector<int>>& board) {
	int largeNum = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			largeNum = max(largeNum, board[i][j]);
	return (largeNum);
}

bool promising(vector<vector<int>>& board, int depth) {
	int expectNum = findLagreNum(board) * pow(2, 5 - depth);
	
	if (expectNum <= answer) return (false);
	else return (true);
}

void changeBoard(vector<vector<int>>& board, int flag) {
	if (flag == UP) {
		for (int x = 0; x < N; x++) {
			queue<int> q;
			int index = 0;

			for (int y = 0; y < N; y++)
				if (board[y][x] != 0) {
					q.push(board[y][x]);
					board[y][x] = 0;
				}
			while (!q.empty()) {
				int pop = q.front();
				q.pop();

				if (!q.empty()) {
					if (q.front() == pop) {
						pop *= 2;
						q.pop();
					}
				}
				board[index++][x] = pop;
			}
		}
	}
	else if (flag == RIGHT) {
		for (int y = 0; y < N; y++) {
			queue<int> q;
			int index = N - 1;

			for (int x = N - 1; x >= 0; x--)
				if (board[y][x] != 0) {
					q.push(board[y][x]);
					board[y][x] = 0;
				}
			while (!q.empty()) {
				int pop = q.front();
				q.pop();

				if (!q.empty()) {
					if (q.front() == pop) {
						pop *= 2;
						q.pop();
					}
				}
				board[y][index--] = pop;
			}
		}
	}
	else if (flag == DOWN) {
		for (int x = 0; x < N; x++) {
			queue<int> q;
			int index = N - 1;

			for (int y = N - 1; y >= 0; y--)
				if (board[y][x] != 0) {
					q.push(board[y][x]);
					board[y][x] = 0;
				}
			while (!q.empty()) {
				int pop = q.front();
				q.pop();
				
				if (!q.empty()) {
					if (q.front() == pop) {
						pop *= 2;
						q.pop();
					}
				}
				board[index--][x] = pop;
			}
		}
	}
	else if (flag == LEFT) {
		for (int y = 0; y < N; y++) {
			queue<int> q;
			int index = 0;
		
			for (int x = 0; x < N; x++)
				if (board[y][x] != 0) {
					q.push(board[y][x]);
					board[y][x] = 0;
				}
			while (!q.empty()) {
				int pop = q.front();
				q.pop();

				if (!q.empty()) {
					if (q.front() == pop) {
						pop *= 2;
						q.pop();
					}
				}
				board[y][index++] = pop;
			}
		}
	}
}

void dfs(vector<vector<int>> board, int depth) {
	if (depth == 5) {
		answer = max(answer, findLagreNum(board));
		return;
	}	
	if (!promising(board, depth))	return;

	for (int flag = 0; flag < 4; flag++) {
		vector<vector<int>> nextBoard(N, vector<int>(N));
		
		copy(board.begin(), board.end(), nextBoard.begin());
		changeBoard(nextBoard, flag);
		dfs(nextBoard, depth + 1);
	}
}

int solution() {
	dfs(board, 0);
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	board.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0, num; j < N; j++) {
			cin >> num;
			board[i][j] = num;
		}
	cout << solution() << endl;
}

https://www.acmicpc.net/problem/15685

#include <iostream>
#include <vector>
using namespace std;

#define CHFLAG(N) ((N) < 4 ? (N) : 0)
bool map[101][101];
int N;
vector<vector<int>> input;
int answer;

void draw(vector<int>& info) {
	static const int dy[] = { 0, -1, 0, 1 };
	static const int dx[] = { 1, 0, -1, 0 };

	int x = info[0], y = info[1];
	int flag = info[2], gen = info[3];
	vector<int> curve;

	//0 gen
	map[y][x] = true;
	y += dy[flag], x += dx[flag];
	map[y][x] = true;
	curve.push_back(flag);
	//1~gen
	for (int g = 1; g <= gen; g++) {
		int size = curve.size();

		for (int i = size - 1; i >= 0; i--) {
			flag = CHFLAG(curve[i] + 1);
			y += dy[flag], x += dx[flag];
			map[y][x] = true;
			curve.push_back(flag);
		}
	}
}

void count_square() {
	int cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				cnt++;
	answer = cnt;
}

int solution() {
	for (int i = 0; i < N; i++)
		draw(input[i]);
	count_square();
	return (answer);	
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);	cin.tie(NULL);

	cin >> N;
	input.resize(N, vector<int>(4));
	for (int i = 0; i < N; i++) 
		for (int j = 0, in; j < 4; j++) {
			cin >> in;
			input[i][j] = in;
		}
	cout << solution() << endl;
}

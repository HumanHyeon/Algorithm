#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int N, M, K;
int food[11][11];
vector<vector<vector<int>>> trees(11, vector<vector<int>>(11, vector<int>()));
int b[11][11];
int answer;

const int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)	return (false);
	return (true);
}

bool canBreeding(int age) {
	if (age < 5)		return (false);
	if (age % 5 == 0)	return (true);
	return (false);
}

void spring_and_summer_and_winter() {
	for (int y = 0; y < N; y++) 
		for (int x = 0; x < N; x++) {
			int deadFood = 0;
			int size = trees[y][x].size();

			for (int i = 0; i < size; i++) {
				int age = trees[y][x][i];
				
				if (b[y][x] >= age) {
					b[y][x] -= age;
					++trees[y][x][i];
				}
				else {
					deadFood += (age / 2);
					trees[y][x].erase(trees[y][x].begin() + i);
					--i;
					--size;
				}
			}
			b[y][x] += (deadFood + food[y][x]);
		}
}

void autumn() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			for (int i = 0; i < trees[y][x].size(); i++) {
				int age = trees[y][x][i];
	
				if (canBreeding(age))
					for (int flag = 0; flag < 8; flag++) {
						int ny = y + dy[flag], nx = x + dx[flag];

						if (isValid(ny, nx))
							trees[ny][nx].insert(trees[ny][nx].begin(), 1);
					}
			}
		}
}

void solution() {
	for (int year = 0; year < K; year++) {
		spring_and_summer_and_winter();
		autumn();
	}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			answer += trees[y][x].size();
}

void init() {
	cin >> N >> M >> K;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			cin >> food[y][x];	
			b[y][x] = 5;
		}

	for (int i = 0; i < M; i++) {
		int y, x, age;
		cin >> y >> x >> age;

		trees[y - 1][x - 1].push_back(age);

	}

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) 
			sort(trees[y][x].begin(), trees[y][x].end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	init();
	solution();

	cout << answer;
}

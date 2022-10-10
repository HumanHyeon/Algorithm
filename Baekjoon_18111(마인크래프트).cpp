#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, B;
int map[501][501];

int maxVal;
pair<int, int> answer;


bool validHeight(int target) {
	int required = 0 , notRequired = 0;

	for (int y = 0; y < N; y++) 
		for (int x = 0; x < M; x++) {
			if (map[y][x] > target)	notRequired += (map[y][x] - target);
			else if (map[y][x] == target) continue;
			else required += (target - map[y][x]);
		}
	required = B + notRequired - required;
	
	if (required >= 0)	return (true);
	else return (false);
}

int computeTime(int target) {
	int time = 0;

	for (int y = 0; y < N; y++) 
		for (int x = 0; x < M; x++) {
			if (map[y][x] > target)	time += ((map[y][x] - target) * 2);
			else if (map[y][x] == target) continue;
			else time += (target - map[y][x]);
		}

	return (time);
}

void solution() {
	for (int height = maxVal; height >= 0; --height) {
		bool possibility = validHeight(height);

		if (possibility) {
			int time = computeTime(height);
			
			if (answer.first > time)
				answer = make_pair(time, height);
		}
	}
}


void init() {
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0,val; j < M; j++) {
			cin >> val;

			map[i][j] = val;
			if (maxVal < val) maxVal = val;
		}
	answer = make_pair(987654321, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	solution();

	cout << answer.first << " " << answer.second;
}

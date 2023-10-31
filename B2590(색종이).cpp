#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG 0

int paper[7];
int cache[7];
int answer;

void solution() {
	answer = paper[6];

	answer += paper[5];
	cache[1] = (11 * paper[5]);
	
	answer += paper[4];
	cache[2] = (5  * paper[4]);

	while (paper[3] >= 4) {
		++answer;
		paper[3] -= 4;
	}
	if (paper[3] > 0) {
		++answer;
		
		if (paper[3] == 3) {
			++cache[2];
			cache[1] += 5;
		}
		else if (paper[3] == 2) {
			cache[2] += 3;
			cache[1] += 6;
		}
		else if (paper[3] == 1) {
			cache[2] += 5;
			cache[1] += 7;
		}
	}
	
	if (paper[2] <= cache[2]) {
		cache[2] -= paper[2];
		cache[1] += (cache[2] * 4);
	}
	else {
		paper[2] -= cache[2];

		while (paper[2] >= 9) {
			++answer;
			paper[2] -= 9;
		}
		if (paper[2] > 0) {
			++answer;
			cache[1] += (36 - (4 * paper[2]));
		}
	}

	if (paper[1] <= cache[1]) {

	}
	else {
		paper[1] -= cache[1];
		
		while (paper[1] >= 36) {
			++answer;
			paper[1] -= 36;
		}
		if (paper[1] > 0)
			++answer;
	}
}

void input() {
	for (int i = 1; i <= 6; ++i)
		cin >> paper[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	input();
	solution();

	cout << answer;
}

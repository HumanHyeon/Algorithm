https://www.acmicpc.net/problem/1182

#include <iostream>
#include <map>
using namespace std;

int N, S;
int num[41];
map<int, int> m;
long long answer;

void leftSet(int idx, int accumulate) {
	if (idx == N / 2) {
		m[accumulate]++;
		return;
	}
	leftSet(idx + 1, accumulate + num[idx]);
	leftSet(idx + 1, accumulate);
}

void rightSet(int idx, int accumulate) {
	if (idx == N) {
		answer += m[S - accumulate];
		return;
	}
	rightSet(idx + 1, accumulate + num[idx]);
	rightSet(idx + 1, accumulate);
}

void solution() {
	leftSet(0, 0);
	rightSet(N / 2, 0);
	if (S == 0)	answer--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	solution();
	cout << answer << endl;
}

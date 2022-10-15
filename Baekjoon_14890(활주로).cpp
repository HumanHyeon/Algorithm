#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
int b[101][101];
int answer;

bool canPath(vector<int>& v) {
	int before = v[0], size = 1, index = 1;

	while (index < N) {
		int now = v[index];

		if (now == before) {
			size++;
			index++;
		}
		else if (now == before - 1) {	//낮음
			if (index + L - 1 >= N)	return (false);

			for (int i = index; i < index + L; i++)
				if (before - v[i] != 1)
					return (false);
		
			before = v[index];
			size = 0;
			index += L;

		}
		else if (now == before + 1) {	//높음
			if (size < L)	return (false);
			size = 1;
			before = v[index];
			index++;
		}
		else
			return (false);
	}

	return (true);
}

void solution() {
	for (int i = 0; i < N; i++) {
		vector<int> hor, ver;

		for (int j = 0; j < N; j++) {
			hor.push_back(b[i][j]);
			ver.push_back(b[j][i]);
		}

		if (canPath(hor))	answer++;
		if (canPath(ver))	answer++;
	}
}

void init() {
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> b[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	init();
	solution();

	cout << answer;
}

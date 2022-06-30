https://www.acmicpc.net/problem/2467

#include <iostream>
#include <vector>
using namespace std;

#define MP(A, B) make_pair((A), (B))
typedef pair<int, int> pii;

vector<int> liquid;
int N;

pii answer;

void solution() {
	if (liquid[0] >= 0) {
		answer = pii(liquid[0], liquid[1]);
		return;
	}
	else if (liquid[liquid.size() - 1] < 0) {
		answer = pii(liquid[N - 2], liquid[N - 1]);
		return;
	}
	
	int diff;
	int left = 0, right = N - 1;

	diff = abs(liquid[left] + liquid[right]);
	answer = pii(liquid[left], liquid[right]);

	while (left < right) {
		int tmpDiff = liquid[left] + liquid[right];
		if (abs(tmpDiff) < diff) {
			diff = abs(tmpDiff);
			answer = pii(liquid[left], liquid[right]);
		}
		if (tmpDiff <= 0)	left++;
		else				right--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	for (int i = 0, input; i < N; i++) {
		cin >> input;
		liquid.push_back(input);
	}

	solution();
	cout << answer.first << " " << answer.second << endl;
}

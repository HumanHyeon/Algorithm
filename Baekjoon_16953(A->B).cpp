https://www.acmicpc.net/problem/16953

#include <iostream>
#include <queue>
using namespace std;

long long A, B;
long long answer;

void solution() {
	queue <pair<long long, long long>> q;

	q.push(make_pair(A, 1));
	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		if (p.first == B) {
			answer = p.second;
			break;
		}
		else if (p.first > B)	continue;

		q.push(make_pair(p.first * 2, p.second + 1));
		q.push(make_pair(p.first * 10 + 1, p.second + 1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> A >> B;
	answer = -1;
	solution();
	cout << answer << endl;
}

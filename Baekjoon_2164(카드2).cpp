https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int solution() {
	int front;

	while (q.size() > 1) {
		q.pop();
		front = q.front();
		q.pop();
		q.push(front);
	}
	return (q.front());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) q.push(i);
	cout << solution() << endl;
}

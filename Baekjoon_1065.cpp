//https://www.acmicpc.net/problem/1065

#include <iostream>
using namespace std;

int solution(int n) {
	int answer;
	if (n < 100)
		return (n);

	answer = 99;
	for (int i = 100; i <= n; i++) {
		if (((int)(i / 100) - ((i / 10) % 10)) == (((i / 10) % 10) - i % 10))
			answer++;
	}
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;

	cin >> n;
	cout << solution(n);
}

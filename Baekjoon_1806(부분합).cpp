https://www.acmicpc.net/problem/1806

#include <iostream>
using namespace std;

int N, S;
int seq[100001];


int solution() {
	int answer = 987654321;
	int left = 0, right = 0, cnt = 1, sum = seq[0];

	while (left <= right && right < N) {
		if (sum >= S) {
			answer = min(answer, cnt);
			sum -= seq[left++];
			cnt--;
		}
		else {
			sum += seq[++right];
			cnt++;
		}
	}

	return (answer == 987654321 ? 0 : answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) 
		cin >> seq[i];
	cout << solution() << endl;
}

https://www.acmicpc.net/problem/14501

#include <iostream>
using namespace std;

pair<int, int> list[16];
int dp[16];
int N;

//int solution() {
//	int answer = -987654321;
//
//	dp[1] = (1 + (list[1].first - 1) <= N ? list[1].second : 0);
//	for (int i = 2; i <= N; i++) {
//		int T = list[i].first, P = list[i].second;
//
//		dp[i] = (i + (T - 1) <= N ? P : 0);
//		if (i + (T - 1) > N)	continue;
//		for (int j = 1; j < i; j++) {
//			int Tj = list[j].first;
//
//			if (j + (Tj - 1) < i)
//				dp[i] = max(dp[i], dp[j] + P);
//		}
//		answer = max(answer, dp[i]);
//	}
//	return (answer);
//}

int solution() {
	int answer;

	dp[N] = (list[N].first == 1 ? list[N].second : 0);
	answer = dp[N];
	for (int i = N - 1; i >= 1; i--) {
		int T = list[i].first, P = list[i].second;

		dp[i] = dp[i + 1];
		if (i + (T - 1) <= N)	//i번째 p를 넣을 수 있는 경우
			dp[i] = max(dp[i + 1], P + dp[i + T]);
		answer = max(answer, dp[i]);
	}
	return (answer);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int T, P;
		
		cin >> T >> P;
		list[i] = make_pair(T, P);
	}
	cout << solution() << endl;
}

https://www.acmicpc.net/problem/2098

#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 16
using namespace std;

int N;
int W[MAX][MAX];

int dp[MAX][1 << MAX];

int tsp(int node, int key) {
	if (key == (1 << N) - 1) {
		if (W[node][0] == 0)	return INF;
		return W[node][0];
	}

	if (dp[node][key] != INF)	return (dp[node][key]);

	for (int i = 0; i < N; i++) {
		if (W[node][i] == 0 || key & (1 << i)) continue;
		dp[node][key] = min(dp[node][key], tsp(i, key | (1 << i)) + W[node][i]);
	}
	return (dp[node][key]);
}

int solution() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < (1 << MAX); j++)
			dp[i][j] = INF;
	return (tsp(0, 1 << 0));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
	cout << solution() << endl;
}

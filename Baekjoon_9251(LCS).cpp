https://www.acmicpc.net/problem/9251

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int solution(string s1, string s2) {
	for (int i = 0; i < 1001; i++)
		memset(dp[i], 0, sizeof(dp[i]));

	for (int i = 1; i <= s1.size(); i++)
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	return (dp[s1.size()][s2.size()]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	string s1, s2;		cin >> s1 >> s2;
	cout << solution(s1, s2) << endl;
}

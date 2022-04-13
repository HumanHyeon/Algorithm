https://www.acmicpc.net/problem/9252

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int dp[1001][1001];

string solution(string s1, string s2) {
	string answer = "";
	
	for (int i = 0; i < 1001; i++)
		memset(dp[i], 0, sizeof(dp[i]));

	for (int i = 1; i <= s1.size(); i++)
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	int len1 = s1.size(), len2 = s2.size();
	cout << dp[len1][len2] << endl;
	
	while (len1 >= 1 && len2 >= 1) {
		if (dp[len1][len2] == dp[len1 - 1][len2])	len1--;
		else if (dp[len1][len2] == dp[len1][len2 - 1])	len2--;
		else if (dp[len1][len2] == dp[len1 - 1][len2 - 1] + 1) {
			answer = s1[len1 - 1] + answer;
			len1--;
			len2--;
		}
	}
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	string s1, s2;		cin >> s1 >> s2;
	cout << solution(s1, s2) << endl;
}

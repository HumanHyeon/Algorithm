https://www.acmicpc.net/problem/2342

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 100001;

const int MV_SAME = 1;
const int MV_MID = 2;
const int MV_NEAR = 3;
const int MV_OPPO = 4;

const int MIDDLE = 0;
const int UP = 1;
const int LEFT = 2;
const int DOWN = 3;
const int RIGHT = 4;

vector<int> inputs;
int table[MAX][5][5];
int dp[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = INF;
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				table[i][j][k] = INF;
	}
}

int calcFlagVal(int std, int target) {
	if (std == MIDDLE) {
		return MV_MID;
	}
	else if (std == UP) {
		if (target == LEFT || target == RIGHT) return MV_NEAR;
		else if (target == DOWN) return MV_OPPO;
		else if (target == UP) return MV_SAME;
	}
	else if (std == LEFT) {
		if (target == UP || target == DOWN) return MV_NEAR;
		else if (target == RIGHT) return MV_OPPO;
		else if (target == LEFT) return MV_SAME;
	}
	else if (std == DOWN) {
		if (target == LEFT || target == RIGHT) return MV_NEAR;
		else if (target == UP) return MV_OPPO;
		else if (target == DOWN) return MV_SAME;
	}
	else if (std == RIGHT) {
		if (target == UP || target == DOWN) return MV_NEAR;
		else if (target == LEFT) return MV_OPPO;
		else if (target == RIGHT) return MV_SAME;
	}
}

int solution() {
	int step = 0;
	
	for (int cmd : inputs){
		if (step == 0) {
			table[0][0][cmd] = MV_MID;
			table[0][cmd][0] = MV_MID;
			dp[0] = MV_MID;
		}
		else {
			int minVal = INF;

			for (int left = 0; left < 5; left++) {
				for (int std = 0; std < 5; std++) {
					int val = table[step - 1][left][std];
					
					if (val == INF) continue;

					val += calcFlagVal(std, cmd);
					table[step][left][cmd] = min(table[step][left][cmd], val);

					minVal = min(minVal, val);
				}
			}

			for (int right = 0; right < 5; right++) {
				for (int std = 0; std < 5; std++) {
					int val = table[step - 1][std][right];

					if (val == INF) continue;

					val += calcFlagVal(std, cmd);
					table[step][cmd][right] = min(table[step][cmd][right], val);

					minVal = min(minVal, val);
				}
			}
			dp[step] = minVal;
		}
		step++;
	}
	return (dp[inputs.size() - 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	while (true) {
		int num;
		cin >> num;
		if (num == 0) break;
		inputs.push_back(num);
	}
	init();
	cout << solution() << endl;
}

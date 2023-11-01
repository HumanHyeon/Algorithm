#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int> > trace;
char status[1001];	//E T L
int cost[1001];	// 가격
bool visited[1001]; //방문 여부

bool answer;

void dfs(int id = 1, int accumulate = 0) {
	if (answer)
		return;

	if (status[id] == 'L') {
		if (accumulate < cost[id])
			accumulate = cost[id];
	}
	else if (status[id] == 'T') {
		if (accumulate < cost[id])
			return;
		else
			accumulate -= cost[id];
	}

	if (id == n) {
		answer = true;
		return;
	}

	for (int i = 0; i < trace[id].size() ; ++i) {
		const int& tmp = trace[id][i];
		if (visited[tmp])
			continue;

		visited[tmp] = true;
		dfs(tmp, accumulate);
		visited[tmp] = false;
	} 
}

void solution() {
	visited[1] = true;
	dfs();
}

void input() {
	answer = false;
	trace.clear();
	trace.resize(n + 1);

	for (int i = 0; i < 1001; ++i)
		visited[i] = false;
		
	for (int i = 1; i <= n; ++i) {
		cin >> status[i];
		cin >> cost[i];

		while (true) {
			int tmp;
			cin >> tmp;

			if (tmp == 0)
				break;

			trace[i].push_back(tmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	while (true) {
		cin >> n;

		if (n == 0)
			break;
		input();
		solution();

		cout << (answer ? "Yes" : "No") << "\n";
	}	
}

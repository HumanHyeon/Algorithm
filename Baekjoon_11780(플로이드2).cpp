https://www.acmicpc.net/problem/11780

#include <iostream>
#include <memory.h>
#include <vector>
#define INF 987654321
using namespace std;

int N, M;
int G[101][101];
int path[101][101];
vector<int> router;

void findRouter(int start, int end) {
	//if (start == end) {
	//	router.push_back(end);
	//	return;
	//}
	if (path[start][end] != 0) {
		findRouter(start, path[start][end]);
		findRouter(path[start][end], end);
	}
	else router.push_back(end);  //findRouter(end, end);
}

void solution() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (i == k) continue;
			for (int j = 1; j <= N; j++) {
				if (k == j || i == j)	continue;
				if (G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (G[i][j] == INF)	G[i][j] = 0;

	//////////////////////////////////////////////

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << G[i][j] << " ";
		cout << endl;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (G[i][j] == 0)	cout << "0" << endl;
			else {								
				router.clear();
				router.push_back(i);
				findRouter(i, j);
				cout << router.size() << " ";
				for (auto element : router)
					cout << element << " ";
				cout << endl;
			}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);	cin.tie(NULL);
	
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			G[i][j] = INF;

	cin >> N >> M;
	for (int i = 0, source, dest, weight; i < M; i++) {
		cin >> source >> dest >> weight;
		G[source][dest] = min(G[source][dest], weight);
	}
	
	solution();
}

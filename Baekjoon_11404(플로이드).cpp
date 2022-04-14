https://www.acmicpc.net/problem/11404

#include <iostream>
#include <memory.h>
#define INF 987654321
using namespace std;

int N, M;
int G[101][101];

void solution() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (i == k) continue;
			for (int j = 1; j <= N; j++) {
				if (k == j || i == j)	continue;
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (G[i][j] == INF)	G[i][j] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);	cin.tie(NULL);

	for (int i = 1; i <= 100; i++) 
		for (int j = 1; j <= 100; j++)
			G[i][j] = INF;
	//memset(G, -1, sizeof(G));
	
	cin >> N >> M;
	for (int i = 0, source, dest, weight; i < M; i++) {
		cin >> source >> dest >> weight;
		G[source][dest] = min(G[source][dest], weight);
	}
	
	solution();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << G[i][j] << " ";
		cout << endl;
	}
}

https://www.acmicpc.net/problem/2887

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y, z;
	int id;
} Planet;

typedef struct {
	int pId1, pId2, weight;
} Tunnel;

int N, answer;
vector<Planet> pData;
vector<Tunnel> tData;
vector<int> dSet;

bool sortByX(Planet a, Planet b) {
	return (a.x < b.x);
}

bool sortByY(Planet a, Planet b) {
	return (a.y < b.y);
}

bool sortByZ(Planet a, Planet b) {
	return (a.z < b.z);
}

bool sortTunnel(Tunnel a, Tunnel b) {
	return (a.weight < b.weight);
}

void init() {
	//Edge Init
	sort(pData.begin(), pData.end(), sortByX);
	for (int i = 0; i < N - 1; i++)
		tData.push_back({ pData[i].id, pData[i + 1].id, abs(pData[i].x - pData[i + 1].x) });
	sort(pData.begin(), pData.end(), sortByY);
	for (int i = 0; i < N - 1; i++)
		tData.push_back({ pData[i].id, pData[i + 1].id, abs(pData[i].y - pData[i + 1].y) });
	sort(pData.begin(), pData.end(), sortByZ);
	for (int i = 0; i < N - 1; i++)
		tData.push_back({ pData[i].id, pData[i + 1].id, abs(pData[i].z - pData[i + 1].z) });
	
	sort(tData.begin(), tData.end(), sortTunnel);

	//Disjoint Set Init
	dSet.resize(N + 1);
	for (int i = 1; i <= N; i++)
		dSet[i] = i;
}

int find(int node) {
	if (dSet[node] == node) return (node);
	return dSet[node] = find(dSet[node]);
}

void unionSet(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);
	
	if (node1 < node2)	dSet[node2] = node1;
	else dSet[node1] = node2;
}

void run() {
	for (const auto fetch : tData) {
		int pHead1 = find(fetch.pId1);
		int pHead2 = find(fetch.pId2);

		if (pHead1 != pHead2) {
			unionSet(pHead1, pHead2);
			answer += fetch.weight;
		}
	}
}

int solution() {
	init();
	run();
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	pData.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> pData[i].x >> pData[i].y >> pData[i].z;
		pData[i].id = i + 1;
	}
	cout << solution() << endl;
}

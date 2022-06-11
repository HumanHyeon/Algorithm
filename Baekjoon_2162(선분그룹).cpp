https://www.acmicpc.net/problem/2162

#include <iostream>
#include <algorithm>
using namespace std;

#define MP(A, B) make_pair((A), (B))
typedef pair<int, int> pii;

typedef struct {
	int x1, y1;
	int x2, y2;
} Segment;

int N;
Segment segment[3001];
int dSet[3001];
pii answer;

int ccw(pii x, pii y, pii z) {
	long long a = x.first * y.second + y.first * z.second + z.first * x.second;
	long long b = x.second * y.first + y.second * z.first + z.second * x.first;

	if (a - b > 0) return 1;
	else if (a - b == 0) return 0;
	else if (a - b < 0) return -1;
}

bool isMeet(Segment a, Segment b) {
	pii A = MP(a.x1, a.y1);
	pii B = MP(a.x2, a.y2);
	pii C = MP(b.x1, b.y1);
	pii D = MP(b.x2, b.y2);

	int ABC = ccw(A, B, C);
	int ABD = ccw(A, B, D);
	int CDA = ccw(C, D, A);
	int CDB = ccw(C, D, B);

	if (ABC * ABD == 0 && CDA * CDB == 0) {
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		
		if (A <= D && C <= B) return (true);
		else return (false);
	}
	else {
		if (ABC * ABD <= 0 && CDA * CDB <= 0)	return (true);
		else	return (false);
	}
}

int find(int node) {
	if (dSet[node] == node)	return (node);
	return dSet[node] = find(dSet[node]);
}

void unionParent(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);

	if (node1 < node2)	dSet[node2] = node1;
	else	dSet[node1] = node2;
}

void solution() {
	int cache[3001] = { 0, };

	for (int i = 0; i < N; i++)	dSet[i] = i;

	for (int std = 0; std < N; std++) 
		for (int cmp = std + 1; cmp < N; cmp++) 
			if (isMeet(segment[std], segment[cmp])) 
				unionParent(std, cmp);
	
	for (int i = 0; i < N; i++)
		cache[find(i)]++;

	for (int i = 0; i < N; i++) {
		if (cache[i] > 0)	answer.first++;
		answer.second = max(answer.second, cache[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> segment[i].x1 >> segment[i].y1 >> segment[i].x2 >> segment[i].y2;

	solution();
	cout << answer.first << "\n" << answer.second << endl;
}

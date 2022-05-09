https://www.acmicpc.net/problem/1202

#include <iostream>
#include <queue>
#include <set>
using namespace std;

#define mp(A, B) make_pair((A), (B))
typedef pair<int, int> pii;

struct compare{
	bool operator() (pii& a, pii& b) {
		if (a.second == b.second)
			return (a.first > b.first);
		return (a.second < b.second);
	}
};

priority_queue<pii, vector<pii>, compare> pq;
multiset<int> ms;
int N, K;
long long answer;

void solution() {
	while (!pq.empty()) {
		if (ms.size() == 0)	break;
		
		pii jewelry = pq.top();
		pq.pop();
	
		multiset<int>::iterator pos = ms.lower_bound(jewelry.first);
		if (pos == ms.end())	continue;
		answer += jewelry.second;
		ms.erase(pos);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0, M, V; i < N; i++) {
		cin >> M >> V;
		pq.push(mp(M, V));
	}
	for (int i = 0, C; i < K; i++) {
		cin >> C;
		ms.insert(C);
	}
	
	solution();
	cout << answer << endl;
}

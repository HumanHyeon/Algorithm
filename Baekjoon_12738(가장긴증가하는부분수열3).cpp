https://www.acmicpc.net/problem/12738

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int seq[1000001];
int idxInfo[1000001];
int N;
vector<int> lis;

void solution() {
	int end = 1;

	lis.push_back(seq[0]);
	idxInfo[0] = 0;
	for (int i = 1; i < N; i++) {
		int num = seq[i];

		int index = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
			
		if (index == lis.size()) {
			lis.emplace_back(num);
			idxInfo[i] = lis.size() - 1;
		}
		else {
			lis[index] = num;
			idxInfo[i] = index;
		}
	}
}

void printAnswer() {
	stack<int> s;
	int stdIndex = lis.size() - 1;

	cout << lis.size() << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	solution();
	printAnswer();
}

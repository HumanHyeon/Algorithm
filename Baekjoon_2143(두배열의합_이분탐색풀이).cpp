https://www.acmicpc.net/problem/2143

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;
vector<int> B;
int T;
int N, M;

long long solution() {
	long long answer = 0;
	vector<int> subSetA;
	vector<int> subSetB;

	for (int start = 0; start < N; start++) {
		int sum = A[start];
		subSetA.push_back(sum);
		
		for (int j = start + 1; j < N; j++) {
			sum += A[j];
			subSetA.push_back(sum);
		}
	}

	for (int start = 0; start < M; start++) {
		int sum = B[start];
		subSetB.push_back(sum);

		for (int j = start + 1; j < M; j++) {
			sum += B[j];
			subSetB.push_back(sum);
		}
	}

	sort(subSetB.begin(), subSetB.end());

	for (auto item : subSetA) {
		int diff = T - item;
		auto ub = upper_bound(subSetB.begin(), subSetB.end(), diff);
		auto lb = lower_bound(subSetB.begin(), subSetB.end(), diff);
		answer += (ub - lb);
	}
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> T;
	cin >> N;
	for (int i = 0, input; i < N; i++) {
		cin >> input;
		A.push_back(input);
	}
	cin >> M;
	for (int i = 0, input; i < M; i++) {
		cin >> input;
		B.push_back(input);
	}
	cout << solution() << endl;
}

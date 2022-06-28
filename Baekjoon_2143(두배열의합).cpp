https://www.acmicpc.net/problem/2143

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> A;
vector<int> B;
int T;
int N, M;

long long solution() {
	long long answer = 0;
	unordered_map<int, int> subSet;

	for (int start = 0; start < N; start++) {
		int sum = A[start];
		subSet[sum]++;
		
		for (int j = start + 1; j < N; j++) {
			sum += A[j];
			subSet[sum]++;
		}
	}
	for (int start = 0; start < M; start++) {
		int sum = B[start];
		answer += subSet[T - sum];
		for (int j = start + 1; j < M; j++) {
			sum += B[j];
			answer += subSet[T - sum];
		}
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

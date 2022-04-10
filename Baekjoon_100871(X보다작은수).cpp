https://www.acmicpc.net/problem/10871

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int N, X;
	cin >> N >> X;
	
	vector<int> v;
	for (int i = 0, input; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	for (auto fetch : v) {
		if (fetch >= X)	continue;
		cout << fetch << " ";
	}
	cout << endl;
}

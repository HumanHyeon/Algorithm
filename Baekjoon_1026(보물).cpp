https://www.acmicpc.net/problem/1026

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, sum = 0;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0, input; i < n; i++) {
		cin >> input;
		a[i] = input;
	}
	for (int i = 0, input; i < n; i++) {
		cin >> input;
		b[i] = input;
	}

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), less<int>());

	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];
	cout << sum << endl;
}

https://www.acmicpc.net/problem/2562

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	vector<int> v;
	for (int i = 0, tmp; i < 9; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	cout << *(max_element(v.begin(), v.end())) << endl;
	cout << max_element(v.begin(), v.end()) - v.begin() + 1 << endl;
}

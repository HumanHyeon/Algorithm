#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	long long answer = 0;
	int N, B, C;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	cin >> B >> C;


	for (int i = 0; i < N; i++) {
		int remain = a[i] - B;

		++answer;
		if (remain <= 0)	continue;
		else				answer += ceil((double)remain / C);
	}
	cout << answer << endl;
}

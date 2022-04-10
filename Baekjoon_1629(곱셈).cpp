https://www.acmicpc.net/problem/1629

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	long long int answer = 1;
	long long A, B, C;
	cin >> A >> B >> C;

	while (B > 0) {
		if (B % 2 == 1) {
			answer = (answer * A) % C;
			B--;
		}
		else {
			A = (A * A) % C;
			B /= 2;
		}
	}
	cout << answer << endl;
}

https://www.acmicpc.net/problem/20149

#include <iostream>
#include <algorithm>
using namespace std;

#define MP(A, B) make_pair((A), (B))
typedef pair<long, long> pll;

pll A, B, C, D;

int ccw(pll x, pll y, pll z) {
	long long a = x.first * y.second + y.first * z.second + z.first * x.second;
	long long b = x.second * y.first + y.second * z.first + z.second * x.first;

	if (a - b > 0) return 1;
	else if (a - b == 0) return 0;
	else if (a - b < 0) return -1;
}

void calcMeet() {
	double x = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
	double y = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
	double p = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);

	if (p == 0) {
		if (A <= C && B == C)	cout << C.first << " " << C.second << endl;
		else if (A >= C && A == D)	cout << A.first << " " << A.second << endl;
	}
	else
		cout << x / p << " " << y / p << endl;
}

void solution() {
	int ABC = ccw(A, B, C);
	int ABD = ccw(A, B, D);
	int CDA = ccw(C, D, A);
	int CDB = ccw(C, D, B);

	//Straight Line
	if (ABC * ABD == 0 && CDA * CDB == 0) {
		if (A > B)	swap(A, B);
		if (C > D)	swap(C, D);

		if (A <= D && C <= B) {
			cout << "1" << endl;
			calcMeet();
			return ;
		}
		else
			cout << "0" << endl;
			return ;
	}
	else {
		if (ABC * ABD <= 0 && CDA * CDB <= 0) {
			cout << "1" << endl;
			calcMeet();
			return;
		}
		else
			cout << "0" << endl;
			return ;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cout.precision(17);

	cin >> A.first >> A.second >> B.first >> B.second;
	cin >> C.first >> C.second >> D.first >> D.second;

	solution();
}

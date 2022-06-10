https://www.acmicpc.net/problem/17386

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

int solution() {
	int ABC = ccw(A, B, C);
	int ABD = ccw(A, B, D);
	int CDA = ccw(C, D, A);
	int CDB = ccw(C, D, B);

	//Straight Line
	if (ABC * ABD == 0 && CDA * CDB == 0) {
		if (A > B)	swap(A, B);
		if (C > D)	swap(C, D);
		
		if (A <= D && C <= B)	return (1);
		else	return (0);
	}
	else {
		if (ABC * ABD <= 0 && CDA * CDB <= 0)	return (1);
		else	return (0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> A.first >> A.second >> B.first >> B.second;
	cin >> C.first >> C.second >> D.first >> D.second;

	cout << solution() << endl;
}

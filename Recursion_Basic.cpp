#include <iostream>
using namespace std;

void recur2(int n) {
	cout << n << " ";
	if (n >= 15) {
		cout << endl;
		cout << n << " ";
		return;
	}
	recur2(n + 2);
	cout << n << " ";
}

void recur(int n) {
	if (n > 15) {
		cout << endl;
		return;
}
	cout << n << " ";
	recur(n + 2);
	cout << n << " ";
}

int main() {
	recur(3);
}

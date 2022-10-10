#include <iostream>
#include <algorithm>
using namespace std;

int N;
string expression;
int answer;

int compute(int x, char op, int y) {
	if (op == '*')			return (x * y);
	else if (op == '+')		return (x + y);
	else					return (x - y);
}

void solution(int idx, int accumulate) {
	if (idx >= N) {
		answer = max(answer, accumulate);
		return;
	}
	char op = (idx == 0 ? '+' : expression[idx - 1]);
		
	//괄호O
	if (idx + 2 < N) {
		int	bracketResult = compute(expression[idx] - '0', expression[idx + 1], expression[idx + 2] - '0');
		solution(idx + 4, compute(accumulate, op, bracketResult));
	}
	//괄호x
	solution(idx + 2, compute(accumulate, op, expression[idx] - '0'));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;
	cin >> expression;

	answer = -2147483648;
	solution(0, 0);

	cout << answer;
}

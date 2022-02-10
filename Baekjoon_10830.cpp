https://www.acmicpc.net/problem/10830

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long B;
vector<vector<long long>> matrix;
vector<vector<long long>> answer;

void multiple(vector<vector<long long>>& dest, vector<vector<long long>>& src) {
	vector<vector<long long>> tmp(N, vector<long long>(N, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			for (int index = 0; index < N; index++) 
				tmp[y][x] += dest[y][index] * src[index][x];
			tmp[y][x] %= 1000;
		}
	}
	copy(tmp.begin(), tmp.end(), dest.begin());
}

void solution() {
	while (B > 0) {
		cout << "'\t\t" << B << endl;
		if (B % 2 == 1) {
			cout << "\tinner : " << B << endl;
			multiple(answer, matrix);
		}
			
		multiple(matrix, matrix);
		B /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> B;
	matrix.resize(N, vector<long long>(N, 0));
	answer.resize(N, vector<long long>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
		answer[i][i] = 1;
	}
	
	solution();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << answer[i][j] << " ";
		cout << endl;
	}
}

https://www.acmicpc.net/problem/9461

#include <stdio.h>

int main() {
	long long F[101] = {1, 1, 1, 1, };

	for (int i = 4; i <= 100; i++)
		F[i] = F[i - 2] + F[i - 3];
	
	int T;	scanf("%d", &T);
	for (int t = 0, N; t < T; t++) {
		scanf("%d", &N);
		printf("%lld\n", F[N]);
	}
}

https://programmers.co.kr/learn/courses/30/lessons/12934

long long solution(long long n) {
	for (long long i = 0; i * i <= n; i++) 
		if (i * i == n)	return (i + 1) * (i + 1);
	return -1;
}

other Ver
#include <cmath>

long long solution(long long n) {
	long long tmp = sqrt(n);
    return powl(tmp, 2) == n ? powl(tmp + 1, 2) : -1;
}

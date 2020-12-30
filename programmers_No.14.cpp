https://programmers.co.kr/learn/courses/30/lessons/12943

int solution(int n) {
	long long num = n;
	if (num == 1)	return 0;
	for (int i = 1; i <= 500; i++) {
		num % 2 == 0 ? num = num * 3 + 1 : num /= 2;
		if (num == 1)	return i;
	}
	return -1;
}

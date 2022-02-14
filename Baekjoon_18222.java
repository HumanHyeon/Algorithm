https://www.acmicpc.net/problem/18222

import java.util.Scanner;

public class B18222 {
	static long k;
	static int answer;
	
	static int thueMorse(long n) {
		if (n == 0)		return (0);
		if (n == 1)		return (1);
		if (n % 2 == 1)	return (1 - thueMorse(n / 2));
		else			return (thueMorse(n / 2));
	}
	
	static void solution() {
		answer = thueMorse(k - 1);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		k = scan.nextLong();
		solution();
		System.out.println(answer);
	}

}

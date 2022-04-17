https://www.acmicpc.net/problem/1003

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int N;
	static int dp[];
	
	static void init() {
		dp = new int[41];
		
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;
		
		for (int i = 3; i <= 40; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		init();
		
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			if (N == 0) System.out.println(1+ " " + 0);
			else 		System.out.println(dp[N - 1] + " " + dp[N]);
		}
	}
}

https://www.acmicpc.net/problem/12852

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B12852 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int dp[] = new int[N + 1];
		
		dp[0] = dp[1] = 0;
		for (int i = 2; i <= N; i++) {
			dp[i] = dp[i - 1] + 1;
			if (i % 2 == 0) 
				dp[i] = Math.min(dp[i], dp[i / 2] + 1);
			if (i % 3 == 0) 			
				dp[i] = Math.min(dp[i], dp[i / 3] + 1);
		}
		System.out.println(dp[N]);

		while (N != 1) {
			System.out.print(N + " ");
			if (dp[N] == dp[N - 1] + 1)	N--;
			else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1) N /= 2;
			else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1) N /= 3;
		}
		System.out.println("1");
	}

}

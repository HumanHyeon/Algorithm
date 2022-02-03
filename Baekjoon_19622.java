https://www.acmicpc.net/problem/19622

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[] dp;
	static int[][] info;
	static int answer = Integer.MIN_VALUE;
	
	static void input() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		dp = new int[N];
		info = new int[N][3];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			info[i][0] = Integer.parseInt(st.nextToken());
			info[i][1] = Integer.parseInt(st.nextToken());
			info[i][2] = Integer.parseInt(st.nextToken());
		}
		br.close();
	}
	
	static void solution() {
		dp[0] = info[0][2];
		if (N == 1) {
			answer = dp[0];
			return ;
		}	
		dp[1] = Math.max(dp[0], info[1][2]);
		if (N == 2) {
			answer = dp[1];
			return ;
		}
		for (int i = 2; i < N; i++) {
			dp[i] = Math.max(dp[i - 1], dp[i - 2] + info[i][2]);
			answer = Math.max(answer, dp[i]);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		solution();
		System.out.println(answer);
	}

}

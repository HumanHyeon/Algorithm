//https://www.acmicpc.net/problem/1965

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B1965 {
	static int N;
	static int[] boxes;
	static int[] dp;
	static int answer;
	
	static void input() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		boxes = new int[N];
		dp = new int[N];
		st = new StringTokenizer(br.readLine());
		
		for (int i = 0; i < N; i++) {
			boxes[i] = Integer.parseInt(st.nextToken());
			dp[i] = 1;
		}

		br.close();
	}
	
	static void solution() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) 
				if (boxes[j] < boxes[i] && dp[i] <= dp[j])
					dp[i] = dp[j] + 1;
			answer = (answer < dp[i]) ? dp[i] : answer;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		solution();
		System.out.println(answer);
	}

}

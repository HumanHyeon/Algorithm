https://www.acmicpc.net/problem/17404

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B17404 {
	static int N;
	static int RGB[][];
	static int dp[][];
	
	static int answer;
	
	final static int INF = 987654321;
	
	static void solution() {
		dp = new int[N][3];
		answer = INF;
		
		for (int color = 0; color < 3; color++) {
			for (int cmp = 0; cmp < 3; cmp++) {
				if (color == cmp)	dp[0][color] = RGB[0][color];
				else 				dp[0][cmp] = INF;
			}
			
			for (int i = 1; i < N; i++) {
				dp[i][0] = RGB[i][0] + Math.min(dp[i - 1][1], dp[i - 1][2]);
				dp[i][1] = RGB[i][1] + Math.min(dp[i - 1][0], dp[i - 1][2]);
				dp[i][2] = RGB[i][2] + Math.min(dp[i - 1][0], dp[i - 1][1]);
			}
			
			for (int i = 0; i < 3; i++) {
				if (i == color)	continue;
				answer = Math.min(answer, dp[N - 1][i]);
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		RGB = new int[N][3];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			RGB[i][0] = Integer.parseInt(st.nextToken());
			RGB[i][1] = Integer.parseInt(st.nextToken());
			RGB[i][2] = Integer.parseInt(st.nextToken());			
		}
		
		solution();
		System.out.println(answer);
	}

}

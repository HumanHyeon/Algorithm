https://www.acmicpc.net/problem/15652

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B15652 {
	static int N;
	static int M;
	static StringBuilder sb;

	static void combination_with_repetition(int depth, int index, int[] accumulate) {
		if (depth == M) {
			for (int i = 0; i < accumulate.length; i++)
				sb.append(accumulate[i]).append(" ");
			sb.append("\n");
			return ;
		}
		
		for (int i = index; i < N; i++) {
			accumulate[depth] = (i + 1);
			combination_with_repetition(depth + 1, i, accumulate);
		}
	}
	
	static void solution() {
		combination_with_repetition(0, 0, new int[M]);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		sb = new StringBuilder();
		solution();
		System.out.println(sb.toString());
	}
}

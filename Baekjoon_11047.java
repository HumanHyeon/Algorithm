https://www.acmicpc.net/problem/11047

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B11047 {
	static int N;
	static int K;
	static int[] table;
	static int answer;
	
	static void solution() {
		for (int i = N - 1; i >= 0; i--) {
			if (K / table[i] < 1)
				continue;
			answer += (K / table[i]);
			K -= (K / table[i] * table[i]);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		table = new int[N];
		for (int i = 0; i < N; i++)
			table[i] = Integer.parseInt(br.readLine());
		solution();
		System.out.println(answer);
	}
}

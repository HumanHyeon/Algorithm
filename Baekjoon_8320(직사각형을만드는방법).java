https://www.acmicpc.net/problem/8320

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B8320 {
	static int N;
	static int answer;
	
	static void solution() {
		for (int i = 1; i <= N; i++) {
			for (int j = i; i * j <= N; j++)
				answer++;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		answer = 0;
		solution();
		System.out.println(answer);
	}
}

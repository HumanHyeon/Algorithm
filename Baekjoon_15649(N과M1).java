https://www.acmicpc.net/problem/15649

import java.util.ArrayList;
import java.util.Scanner;

public class B15649 {
	static int N;
	static int M;
	static ArrayList<String> answer;
	
	static void permutation(int depth, boolean[] visited, int[] accumulate) {
		if (depth == M) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < accumulate.length; i++)
				sb.append(accumulate[i]).append(" ");
			answer.add(sb.toString());
			return ;
		}
		
		for (int i = 0; i < N; i++) 
			if (!visited[i]) {
				visited[i] = true;
				accumulate[depth] = (i + 1);
				permutation(depth + 1, visited, accumulate);
				visited[i] = false;
			}
	}
	
	static void solution() {
		boolean[] visited = new boolean[N];
		int[] accumulate = new int[M];
		
		permutation(0, visited, accumulate);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		M = scan.nextInt();
		
		answer = new ArrayList<>();
		solution();
		for (String fetch : answer)
			System.out.println(fetch);
	}
}

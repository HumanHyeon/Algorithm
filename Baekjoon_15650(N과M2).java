https://www.acmicpc.net/problem/15650

import java.util.ArrayList;
import java.util.Scanner;

public class B15650 {
	static int N;
	static int M;
	static ArrayList<String> answer;
	
	static void combination(int depth, int index, int[] accumulate) {
		if (depth == M) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < accumulate.length; i++)
				sb.append(accumulate[i]).append(" ");
			answer.add(sb.toString());
			return;
		}
		
		for (int i = index; i < N; i++) {
			accumulate[depth] = (i + 1);
			combination(depth + 1, i + 1, accumulate);
		}
	}
	
	static void solution() {
		combination(0, 0, new int[M]);
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

https://www.acmicpc.net/problem/15666

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B15666 {
	static int N;
	static int M;
	static int[] nums;
	static Set<Integer> input;
	static ArrayList<String> answer;
	
	static void combination_with_repetition(int depth, int index, int[] accumulate) {
		if (depth == M) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < accumulate.length; i++)
				sb.append(accumulate[i]).append(" ");
			answer.add(sb.toString());
			return ;
		}
		
		for (int i = index; i < nums.length; i++) {
			accumulate[depth] = nums[i];
			combination_with_repetition(depth + 1, i, accumulate);
		}
	}
	
	static void solution() {
		int index;
	
		index = 0;
		nums = new int[input.size()];
		for (int fetch : input)
			nums[index++] = fetch;
	
		Arrays.sort(nums);
		combination_with_repetition(0, 0, new int[M]);	
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		M = scan.nextInt();

		input = new HashSet<>();
		for (int i = 0; i < N; i++)
			input.add(scan.nextInt());
		
		answer = new ArrayList<>();
		solution();
		for (String fetch : answer) 
			System.out.println(fetch);
	}

}

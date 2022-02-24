https://www.acmicpc.net/problem/14719

import java.util.Scanner;

public class B14719 {
	static int H, W;
	static int[] data;
	static int answer;
	
	static void solution() {
		for (int i = 1; i < W - 1; i++) {
			int left = 0, right = 0;
			
			for (int j = 0; j < i; j++) 
				left = Math.max(left, data[j]);
			for (int j = i + 1; j < W; j++) 
				right = Math.max(right, data[j]);
			answer += Math.max(Math.min(left, right) - data[i], 0);
		}
	}
	
	static void solution2() {
		int leftMax = 0;
		
		for (int i = 1; i < W - 1; i++) {
			int left = 0, right = 0;
			
			left = Math.max(data[i - 1], leftMax);
			for (int j = i + 1; j < W; j++) 
				right = Math.max(right, data[j]);
			answer += Math.max(Math.min(left, right) - data[i], 0);
			
			leftMax = Math.max(left, leftMax);
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		H = scan.nextInt();
		W = scan.nextInt();
		
		data = new int[W];
		for (int i = 0; i < W; i++)
			data[i] = scan.nextInt();
		
		answer = 0;
		solution2();
		System.out.println(answer);
	}

}

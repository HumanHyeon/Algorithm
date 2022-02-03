//https://www.acmicpc.net/problem/10819

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static int size;
	public static int max;
	
	public static void dfs(int[] arr, int depth) {
		if (depth == size) {
			int output = calc(arr);
			if (output > max)
				max = output;
			return ;
		}
		
		for (int i = 0; i < size; i++) {
			swap(arr, depth, i);
			dfs(arr, depth + 1);
			swap(arr, depth, i);
		}
	}
	
	public static int calc(int[] arr) {
		int sum = 0;
		
		for (int i = 0; i < arr.length - 1; i++) {	
			sum += Math.abs(arr[i] - arr[i + 1]);
		}
		
		return (sum);
	}
	
	public static void swap(int[] arr, int depth, int i) {
		int tmp = arr[depth];
		arr[depth] = arr[i];
		arr[i] = tmp;
	}
	
	public static void main(String[] args) {
		int[] arr;

		Scanner scan = new Scanner(System.in);
		
		size = scan.nextInt();
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = scan.nextInt();
		
		max = Integer.MIN_VALUE;
		dfs(arr, 0);
		
		System.out.print(max);
	}

}

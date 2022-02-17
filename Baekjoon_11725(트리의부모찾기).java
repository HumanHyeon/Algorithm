https://www.acmicpc.net/problem/11725

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B11725 {
	static int N;
	static ArrayList<Queue<Integer>> line;
	static int parent[];
	
	static void dfs(int n) {
		Queue<Integer> fetch;
		int link;
		
		fetch = line.get(n);
		while (!fetch.isEmpty()) {
			link = fetch.poll();
			
			if (parent[link] == 0) {
				parent[link] = n;
				dfs(link);
			}
		}
	}
	
	static void solution() {
		dfs(1);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		parent = new int[N + 1];
		
		line = new ArrayList<Queue<Integer>>();
		for (int i = 0; i <= N; i++)
			line.add(new LinkedList<Integer>());
		
		for (int i = 0, source, dest; i < N - 1; i++) {
			source = scan.nextInt();
			dest = scan.nextInt();
			
			line.get(source).add(dest);
			line.get(dest).add(source);
		}
		
		solution();
		for (int i = 2; i <= N; i++)
			System.out.println(parent[i]);
	}

}

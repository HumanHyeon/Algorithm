https://www.acmicpc.net/problem/1260

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class B1260 {
	static int N, M, V;
	static boolean[][] G;
	static boolean[] cache;
	static Queue<Integer> queue = new LinkedList<>();
	
	static void input() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		
		G = new boolean[N + 1][N + 1];
		
		for (int i = 0; i < M; i++) {
			int first, second;
			
			st = new StringTokenizer(br.readLine());
			first = Integer.parseInt(st.nextToken());
			second = Integer.parseInt(st.nextToken());
			G[first][second] = true;
			G[second][first] = true;
		}
		
		br.close();
	}
	
	static void dfs(int start) {
		cache[start] = true;
		System.out.print(start + " ");

		for (int i = 1; i <= N; i++)
			if (G[start][i] == true && cache[i] == false)
				dfs(i);
	}
	
	static void bfs(int start) {
		queue.add(start);
		cache[start] = true;
		
		while(queue.isEmpty() == false) {
			start = queue.poll();
			System.out.print(start + " ");
			
			for (int i = 0; i <= N; i++)
				if (G[start][i] == true && cache[i] == false) {
					cache[i] = true;
					queue.add(i);
				}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		cache = new boolean[N + 1];
		dfs(V);
		cache = new boolean[N + 1];
		System.out.println();
		bfs(V);
		System.out.println();
	}
}

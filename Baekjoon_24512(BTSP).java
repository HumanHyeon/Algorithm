https://www.acmicpc.net/problem/24512

import java.util.Scanner;

public class B24512 {
	static int N;
	static int M;
	static int[][] graph;
	
	static boolean visited[];
	static int order[];
	static int cost;
	static int answer[];
		
	static void dfs(int depth, int source, int maxCost) {
		if (depth == N) {
			if (graph[source][order[0]] != 0) {		
				maxCost = Math.max(maxCost, graph[source][order[0]]);
				if (cost > maxCost) {
					cost = maxCost;
					answer = order.clone();
				}
				return ;	
			}
		}

		for (int dest = 1; dest <= N; dest++) 
			if (!visited[dest] && graph[source][dest] != 0) {
				visited[dest] = true;
				order[depth] = dest;
				dfs(depth + 1, dest, Math.max(maxCost, graph[source][dest]));
				visited[dest] = false;
			}
	}
	
	static void solution() {
		visited = new boolean[N + 1];
		order = new int[N];

		for (int source = 1; source <= N; source++) {
			visited[source] = true;
			order[0] = source;
			dfs(1, source, Integer.MIN_VALUE);
			visited[source] = false;
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		M = scan.nextInt();
		
		graph = new int[N + 1][N + 1];
		for (int i = 0; i < M; i++){
			int source = scan.nextInt();
			int dest = scan.nextInt();
			int weight = scan.nextInt();
		
			graph[source][dest] = weight;
		}	
		
		cost = Integer.MAX_VALUE;
		answer = new int[N];
		solution();
		if (cost == Integer.MAX_VALUE) System.out.println(-1);
		else {
			System.out.println(cost);
			for (int i = 0; i < N; i++)
				System.out.print(answer[i] + " ");
			System.out.println();
		}
	}
}

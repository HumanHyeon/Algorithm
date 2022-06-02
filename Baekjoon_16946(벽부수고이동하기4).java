https://www.acmicpc.net/problem/16946

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class B16946 {
	static int N, M;
	static int MAP[][];
	static int dy[] = { -1, 0, 1, 0 };
	static int dx[] = { 0, 1, 0, -1 };
 	static int visited[][];
 	static int groupNum[];
	static int answer[][];
 	
	static void print(int MAP[][]) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				sb.append(MAP[i][j]);
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
	
	static boolean is_valid(int y, int x) {
		return !(y < 0 || x < 0 || y >= N || x >= M);	
	}
	
	static void BFS(int y, int x, int group) {
		Queue<int[]> q = new LinkedList<>();
		int cnt = 0;
		
		visited[y][x] = group;
		cnt++;
		q.add(new int[] {y, x});
		
		while (!q.isEmpty()) {
			int nowY = q.peek()[0], nowX = q.peek()[1];
			q.poll();
			
			for (int flag = 0; flag < 4; flag++) {
				int ny = nowY + dy[flag];
				int nx = nowX + dx[flag];
				
				if (is_valid(ny, nx))
					if (MAP[ny][nx] == 0 && visited[ny][nx] == 0) {
						visited[ny][nx] = group;
						cnt++;
						q.add(new int[] { ny, nx });
					}
			}
		}
		groupNum[group] = cnt;
	}
	
	static void solution() {
		answer = new int[N][M];
		visited = new int[N][M];
		groupNum = new int[1000001];
		
		for (int i = 0, group = 1; i < N; i++)
			for (int j = 0; j < M; j++) 
				if (MAP[i][j] == 0 && visited[i][j] == 0) 	BFS(i, j, group++);

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (MAP[y][x] == 1) {
					Set<Integer> s = new HashSet<>();
					int cnt = 1;
					
					for (int flag = 0; flag < 4; flag++) {
						int ny = y + dy[flag];
						int nx = x + dx[flag];
						
						if (is_valid(ny, nx))
							if (MAP[ny][nx] == 0) {
								int group = visited[ny][nx];
								
								if (!s.contains(group)) {
									s.add(group);
									cnt += groupNum[group];
								}
							}
					}
					answer[y][x] = cnt % 10;
				}
				else	answer[y][x] = 0;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		MAP = new int[N][M];
		for (int i = 0; i < N; i++) {
			String input = br.readLine();
			for (int j = 0; j < M; j++)
				MAP[i][j] = input.charAt(j) - '0';
		}
		solution();
		print(answer);
	}

}

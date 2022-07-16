https://www.acmicpc.net/problem/2206

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N, M, K;
	static int MAP[][];
	
	static final int dy[] = { -1, 0, 1, 0 };
	static final int dx[] = { 0, 1, 0, -1 };
	static final int INF = 987654321;
	
	static int cache[][][];
	
	static int answer;
	
	static void init() {
		cache = new int[N][M][K + 1];
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) 
				Arrays.fill(cache[i][j], INF);
	}
	
	static boolean isValid(int y, int x) {
		if (y < 0 || x < 0 || y >= N || x >= M) 	return (false);
		return (true);
	}
	
	static void run() {
		Queue<int[]> q = new LinkedList<>();	//y x move chance
		
		cache[0][0][K] = 1;
		q.add(new int[] { 0, 0, 1, K });
		
		while (!q.isEmpty()) {
			int y = q.peek()[0], x= q.peek()[1], move = q.peek()[2], chance = q.peek()[3];
			q.poll();
			 
			if (y == N - 1 && x == M - 1) {
				answer = move;
				break;
			}
			
			for (int flag = 0; flag < 4; flag++) {
				int ny = y + dy[flag], nx = x + dx[flag];
				
				if (!isValid(ny, nx))	continue;
				
				if (MAP[ny][nx] == 0) {
					if (cache[ny][nx][chance] == INF) {
						cache[ny][nx][chance] = move + 1;
						q.add(new int[] { ny, nx, move + 1, chance });
					}
				}
				else {	//Wall
					if (chance == 0)	continue;
					
					if (cache[ny][nx][chance - 1] > move + 1) {
						cache[ny][nx][chance - 1] = move + 1;
						q.add(new int[] { ny, nx, move + 1, chance - 1});
					}
				}
			}
		}
		if (answer == 0)	answer = -1;
	}
	
	static void solution() {
		init();
		run();
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = 1;
		
		MAP = new int[N][M];
		for (int i = 0; i < N; i++) {
			String input = br.readLine();
			for (int j = 0; j < M; j++) {
				if (input.charAt(j) == '0')
					MAP[i][j] = 0;
				else 
					MAP[i][j] = 1;
			}
		}
		
		solution();
		System.out.println(answer);
	}
}

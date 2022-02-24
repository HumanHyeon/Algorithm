https://www.acmicpc.net/problem/3055

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B3055 {
	static int R;
	static int C;
	static char[][] MAP;
	static int answer;
	
	static ArrayList<int[]> waterPos;
	static int[][] water;
	static int startY, startX, endY, endX;
	
	static final int dy[] = { -1, 0, 1, 0 };
	static final int dx[] = { 0, 1, 0, -1 };
	
	static boolean is_valid(int y, int x) {
		if (y < 0 || x < 0 || y >= R || x >= C)
			return (false);
		if (MAP[y][x] == 'X' || MAP[y][x] == 'S' || MAP[y][x] == '*')
			return (false);
		//도착 지점에 대한 처리 방법이 물이동/고슴도치이동 경우 다르기 때문에 유효성체크하지 않음.
		//물이동 -> 도착 지점 접근 금지
		//고슴도치이동 -> 도착 지점 접근
		return (true);
	}
	
	static void water_min() {
		Queue<int[]>q = new LinkedList<int[]>();
	
		for (int[] fetch : waterPos)
			q.add(fetch);
		
		water = new int[R][C];
		while (!q.isEmpty()) {
			int y = q.peek()[0];
			int x = q.peek()[1];
			int min = q.peek()[2] + 1;
			q.poll();
			
			for (int flag = 0; flag < 4; flag++) {
				int ny = y + dy[flag];
				int nx = x + dx[flag];
				if (is_valid(ny, nx) && water[ny][nx] == 0) {
					if (MAP[ny][nx] == 'D')	//도착 지점에 대해서는 물 이동 금지
						continue;
					water[ny][nx] = min;
					q.add(new int[] { ny, nx, min });
				}
			}
		}
		water[endY][endX] = Integer.MAX_VALUE;	//도착 지점은 언제든 갈 수 있다라는 가정
		water[startY][startX] = -1;
	}
	
	static void bfs() {
		Queue<int[]> q = new LinkedList<int[]>();
		boolean[][] visited = new boolean[R][C];
		
		q.add(new int[] { startY, startX, 0 });
		while (!q.isEmpty()) {
			int y = q.peek()[0];
			int x = q.peek()[1];
			int min = q.peek()[2] + 1;
			q.poll();
			
			if (y == endY && x == endX) 
				answer = Math.min(answer, min - 1);
			
			for (int flag = 0; flag < 4; flag++) {
				int ny = y + dy[flag];	
				int nx = x + dx[flag];
				
				if (is_valid(ny, nx) && (water[ny][nx] > min || water[ny][nx] == 0)) {
					if (visited[ny][nx])
						continue;
					visited[ny][nx] = true;
					q.add(new int[] { ny, nx, min });
				}
			}
		}
	}
	
	static void solution() {
		water_min();
		bfs();
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		R = scan.nextInt();
		C = scan.nextInt();
		scan.nextLine();
		
		MAP = new char[R][C];
		waterPos = new ArrayList<>();
		for (int i = 0; i < R; i++) {
			String input = scan.nextLine();
			for (int j = 0; j < C; j++) {
				MAP[i][j] = input.charAt(j);
				
				if (MAP[i][j] == 'S') {
					startY = i;
					startX = j;
				}
				if (MAP[i][j] == 'D') {
					endY = i;
					endX = j;
				}
				if (MAP[i][j] == '*')
					waterPos.add(new int[] { i, j, 0 });
			}
		}
	
		answer = Integer.MAX_VALUE;
		solution();
		System.out.println((answer == Integer.MAX_VALUE) ? "KAKTUS" : answer);
	}
}

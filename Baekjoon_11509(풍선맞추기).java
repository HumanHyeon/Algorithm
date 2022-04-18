https://www.acmicpc.net/problem/11509

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int H[];
	static int answer;
	
	static void solution() {
		int height[] = new int[1000001];
		
		for (int balloon : H) {
			if (height[balloon] != 0)	height[balloon]--;
			else 						answer++;
			height[balloon - 1]++;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
	
		N = Integer.parseInt(br.readLine());
		H = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) 
			H[i] = Integer.parseInt(st.nextToken());
		solution();
		System.out.println(answer);
	}
}

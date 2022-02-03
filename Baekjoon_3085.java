//https://www.acmicpc.net/problem/3085

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B3085 {
	static int N;
	static char[][] board;
	static int answer;
	
	static void input() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		board = new char[N][N];
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				board[i][j] = (char)br.read();
			br.readLine();
		}
		
		br.close();
	}
	
	static void horizontal() {
		for (int i = 0; i < N; i++) {
			int count = 1;
			
			for (int j = 0; j < N - 1; j++) {
				if (board[i][j] == board[i][j + 1])
					count++;
				else {
					answer = (answer < count) ? count : answer;
					count = 1;
				}
			}
			answer = (answer < count) ? count : answer;
		}
	}
	
	static void vertical() {
		for (int i = 0; i < N; i++) {
			int count = 1;
			
			for (int j = 0; j < N - 1; j++) {
				if (board[j][i] == board[j + 1][i])
					count++;
				else {
					answer = (answer < count) ? count : answer;
					count = 1;
				}
			}
			answer = (answer < count) ? count : answer;
		}
	}
	
	static void solution() {
		char tmp;
		
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N - 1; j++) {
				if (board[i][j] == board[i][j + 1])
					continue;
				
				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;
				
				horizontal();
				vertical();
				
				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;
			}
	
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N - 1; j++) {
				if (board[j][i] == board[j + 1][i])
					continue;
				
				tmp = board[j][i];
				board[j][i] = board[j + 1][i];
				board[j + 1][i] = tmp;
				
				horizontal();
				vertical();
				
				tmp = board[j][i];
				board[j][i] = board[j + 1][i];
				board[j + 1][i] = tmp;
			}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		solution();
		System.out.println(answer);
	}

}

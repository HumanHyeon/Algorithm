https://www.acmicpc.net/problem/2116

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B2116 {
	static int N;
	static int[][] dices;
	static int answer;
	
	//A-F	(index 0-5)
	//B-D	(index 1-3)
	//C-E	(index 2-4)
	//Input: A-B-C-D-E-F
	
	static int findTop(int bottom, int index) {
		int dice[] = dices[index];
		int valueIdx = -1;
		
		for (int i = 0; i < 6; i++)
			if (dice[i] == bottom)
				valueIdx = i;

		if (valueIdx == 0)	return (dice[5]);
		if (valueIdx == 1)	return (dice[3]);
		if (valueIdx == 2)	return (dice[4]);
		if (valueIdx == 3)	return (dice[1]);
		if (valueIdx == 4)	return (dice[2]);
		if (valueIdx == 5)	return (dice[0]);
		return (-1);
	}
	
	static int findLarge(int bottom, int index) {
		int dice[] = dices[index];
		int valueIdx = -1;
		int large = 0;
		
		for (int i = 0; i < 6; i++)	//해당 값 인덱스 찾기
			if (dice[i] == bottom)
				valueIdx = i;
		
		if (valueIdx == 0 || valueIdx == 5) {
			large = Math.max(large, dice[1]);
			large = Math.max(large, dice[2]);
			large = Math.max(large, dice[3]);
			large = Math.max(large, dice[4]);
		}
		else if (valueIdx == 1 || valueIdx == 3) {
			large = Math.max(large, dice[0]);
			large = Math.max(large, dice[2]);
			large = Math.max(large, dice[4]);
			large = Math.max(large, dice[5]);	
		}
		else if (valueIdx == 2 || valueIdx == 4) {
			large = Math.max(large, dice[0]);
			large = Math.max(large, dice[1]);
			large = Math.max(large, dice[3]);
			large = Math.max(large, dice[5]);
		}
		return (large);
	}
	
	static int stackDice(int bottom, int index) {
		if (index == N)
			return (0);
		return (findLarge(bottom, index) + stackDice(findTop(bottom, index), index + 1));
	}
	
	static void solution() {
		for (int bottom = 1; bottom <= 6; bottom++)
			answer = Math.max(answer, findLarge(bottom, 0) + stackDice(findTop(bottom, 0), 1));
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		dices = new int[N][6];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 6; j++)
				dices[i][j] = Integer.parseInt(st.nextToken());
		}
		
		answer = 0;
		solution();
		System.out.println(answer);
	}
}

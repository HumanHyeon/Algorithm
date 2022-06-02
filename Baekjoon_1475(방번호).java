https://www.acmicpc.net/problem/1475

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class B1475 {
	static String N;
	static int answer;
	
	static void solution() {
		int cache[] = new int[10];
		
		Arrays.fill(cache, 1);
		answer++;
		for (int i = 0; i < N.length(); i++) {
			int num = N.charAt(i) - '0';
			
			if (cache[num] > 0) cache[num]--;
			else {
				if (num == 9 || num == 6) {
					if (num == 9) {
						if (cache[6] != 0)
							cache[6]--;
						else {
							for (int j = 0; j < 10; j++)
								cache[j]++;
							cache[9]--;
							answer++;		
						}
					}
					else {
						if (cache[9] != 0)
							cache[9]--;
						else {
							for (int j = 0; j < 10; j++)
								cache[j]++;
							cache[6]--;
							answer++;		
						}
					}
				}
				else {
					for (int j = 0; j < 10; j++)
						cache[j]++;
					cache[num]--;
					answer++;
				}
			}
		}
		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = br.readLine();
		solution();
		System.out.println(answer);
	}
}

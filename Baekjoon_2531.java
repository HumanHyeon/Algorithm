https://www.acmicpc.net/problem/2531

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class B2531 {
	static int N, d, k, c;
	static int[] table;
	static int answer;
	
	static void solution() {
		for (int i = 0; i < N; i++) {
			HashSet<Integer> susi = new HashSet<Integer>();
			boolean coupon = true;
			
			for (int j = 0; j < k; j++) {
				int index = (i + j < N) ? i + j : i + j - N;
				
				if (table[index] == c)
					coupon = false;
				susi.add(table[index]);
			}
			answer = Math.max(answer, (coupon) ? susi.size() + 1 : susi.size());
		}
	}
	
	public static void main(String[] args) throws IOException {
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 StringTokenizer st;
		 
		 st = new StringTokenizer(br.readLine());
		 N = Integer.parseInt(st.nextToken());
		 d = Integer.parseInt(st.nextToken());
		 k = Integer.parseInt(st.nextToken());
		 c = Integer.parseInt(st.nextToken());
		 
		 table = new int[N];
		 for (int i = 0; i < N; i++)
			table[i] = Integer.parseInt(br.readLine());
		 solution();
		 System.out.println(answer);
	}
}

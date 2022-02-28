https://www.acmicpc.net/problem/1244

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B1244 {
	static int N;
	static int[] sw;
	static int stu;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		sw = new int[N + 1];
		st= new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++)
			sw[i] = Integer.parseInt(st.nextToken());
		
		stu = Integer.parseInt(br.readLine());
		for (int cycle = 0; cycle < stu; cycle++) {
			st= new StringTokenizer(br.readLine());
			
			int gender = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			
			if (gender == 1) {
				for (int i = num; i <= N; i += num)
					sw[i] = (sw[i] == 1 ? 0 : 1);
			}
			else {
				sw[num] = (sw[num] == 1 ? 0 : 1);
				for (int size = 1; ; size++) {
					if (num - size == 0 || num + size > N)	break;
					if (sw[num - size] != sw[num + size])	break;
					sw[num - size] = (sw[num - size] == 1 ? 0 : 1);
					sw[num + size] = (sw[num + size] == 1 ? 0 : 1);					
				}
			}
		}
		
		for (int i = 1; i <= N; i++) {
			System.out.print(sw[i] + " ");
			if (i % 20 == 0)	System.out.println();
		}
	}
}

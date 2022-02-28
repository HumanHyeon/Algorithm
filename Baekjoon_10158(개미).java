https://www.acmicpc.net/problem/10158

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class B10158 {
	static int w, h;
	static int p, q;
	static int t;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		p = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(br.readLine());

		int xt = (p + t) % (w * 2);
		int yt = (q + t) % (h * 2);
	
		int x, y;
		if (xt > w)	x = (w * 2) - xt;
		else	x = xt;
		if (yt > h) y = (h * 2) - yt;
		else	y = yt;
		
		bw.write(x + " ");
		bw.write(y + "\n");
		bw.flush();
	}
}

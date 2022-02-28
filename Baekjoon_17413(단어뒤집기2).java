https://www.acmicpc.net/problem/17413

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class B17413 {
	static char[] input;
	static StringBuilder answer;
	
	static void solution() {
		Queue<Character> q = new LinkedList<>();
		Stack<Character> s = new Stack<>();
		int flag = 0;	//0: queue 	1: stack
		
		for (char c : input) {
			if (c == '<') {
				while (!s.isEmpty())
					answer.append(s.pop());
				flag = 1;
			}
			
			if (flag == 0) {
				if (c == ' ') {
					while (!s.isEmpty())
						answer.append(s.pop());
					answer.append(c);
					continue;
				}
				s.add(c);
			}
			else if (flag == 1) {
				if (c == '>') {
					while (!q.isEmpty())
						answer.append(q.poll());
					answer.append(c);
					flag = 0;
					continue;
				}
				q.add(c);
			}
		}
		while (!s.isEmpty())
			answer.append(s.pop());
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		input = br.readLine().toCharArray();
		answer = new StringBuilder();
		solution();
		System.out.println(answer.toString());
	}

}

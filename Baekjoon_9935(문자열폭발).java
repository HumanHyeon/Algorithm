https://www.acmicpc.net/problem/9935

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Stack;

public class Main {
	static String str;
	static String bomb;
	static StringBuilder answer;
	
	static void solution() {
		Stack<Character> s = new Stack<>();
		
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			
			s.push(c);
			if (s.size() >= bomb.length()) {
				boolean check = true;
				
				for (int j = 0; j < bomb.length(); j++)
						if (s.get(s.size() - 1 - j) != bomb.charAt(bomb.length() - 1 - j)) {
							check = false;
							break;
						}
				
				if (check)
					for (int j = 0; j < bomb.length(); j++)
						s.pop();
			}
		}
		
		if (s.size() != 0) {
			answer = new StringBuilder("");
			for (char c : s)
				answer.append(c);
		}
	}
	
	static void solution5() {
		Stack<Character> s = new Stack<>();
		
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			
			s.push(c);
			if (s.get(s.size() - 1) == bomb.charAt(bomb.length() - 1)) {
				boolean check = true;
				
				if (s.size() >= bomb.length()) {
					for (int j = 1; j < bomb.length(); j++) {
						if (s.get(s.size() - 1 - j) != bomb.charAt(bomb.length() - 1 - j)) {
							check = false;
							break;
						}
					}
				}
				
				if (check) {
					for (int j = 0; j < bomb.length(); j++)
						s.pop();
				}
			}
		}
		
		if (s.size() != 0) {
			answer = new StringBuilder("");
			for (char c : s)
				answer.append(c);
		}
	}
	
	static void solution4() {
		StringBuilder sb = new StringBuilder("");
		
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			
			sb.append(c);
			if (sb.charAt(sb.length() - 1) == bomb.charAt(bomb.length() - 1)) {
				boolean check = true;
				
				if (sb.length() >= bomb.length())
					for (int j = 1; j < bomb.length(); j++) 
						if (sb.charAt(sb.length() - 1 - j) != bomb.charAt(bomb.length() - 1 - j)) {
							check = false;
							break;
						}		
					
				if (check) {
					for (int j = 0; j < bomb.length(); j++) 
						sb.replace(sb.length() - 1, sb.length(), "");
						//sb.deletes(sb.length() - 1, sb.length());
				}
			}
		}
		
		if (sb.length() != 0)
			answer = new StringBuilder(sb.toString());
	}
	
	static void solution3() {
		LinkedList<Character> list = new LinkedList<>();
	
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			
			list.add(c);
			if (list.get(list.size() - 1) == bomb.charAt(bomb.length() - 1)) {
				boolean check = true;
				
				if (list.size() >= bomb.length())
					for (int j = 1; j < bomb.length(); j++) 
						if (list.get(list.size() - 1 - j) != bomb.charAt(bomb.length() - 1 - j)) {
							check = false;
							break;
						}		
					
				if (check) {
					for (int j = 0; j < bomb.length(); j++) 
						list.pollLast();
				}
			}
			
		}
		
		if (list.size() != 0) {
			answer = new StringBuilder("");
			for (int i = 0; i < list.size(); i++)
				answer.append(list.get(i));
		}
	}
	
	static void solution2() {
//		int index;
		
//		while ((index = sb.indexOf(bomb)) != -1) 
//			sb.replace(index, index + bomb.length(), "");
		
//		if (sb.length() != 0)	answer = new StringBuilder(sb.toString());
//		else					answer = new StringBuilder("FRULA");
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br =	new BufferedReader(new InputStreamReader(System.in));
		
		str = br.readLine();
		bomb = br.readLine();
	
		answer = new StringBuilder("FRULA");
		solution();
		System.out.println(answer);
	}

}

https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AX69Fyn6JnwDFAS2&contestProbId=AV19AcoKI9sCFAZN&probBoxId=AX69Fyn6Jn0DFAS2+&type=PROBLEM&problemBoxTitle=2%EC%9B%94+3%EC%9D%BC&problemBoxCnt=++1+

import java.util.Scanner;

public class S1289 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();

		sc.nextLine();
		for (int test_case = 1; test_case <= T; test_case++) {
			String s = sc.nextLine();
			int flag = 0;
			int answer = 0;
			
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(i) != (flag + '0')) {
					answer++;
					flag = (flag == 0) ? 1 : 0;
				}
			
			System.out.println("#" + test_case + " " + answer);
		}
	}

}

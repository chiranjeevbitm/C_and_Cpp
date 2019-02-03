package june15;

import java.util.ArrayList;

public class RecursionDemos {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// System.out.println(printSS("abcd", ""));
		// System.out.println(printKPC("196", ""));
		// System.out.println(printMPWDMS(0, 0, 2, 2, ""));
		// System.out.println(printBP(0, 10, ""));
		// int[] arr = { 10, 20, 30, 40, 50, 60, 70 };
		// System.out.println(printSSEqualToComplement(arr, 0, "", "", 0, 0,
		// false));
		// System.out.println(printSSWithSumEqualToTarget(arr, 0, 7, ""));
		int n = 5;
		System.out.println(printNQueens(new boolean[n][n], 0, ""));
//		printSSWithASb("abc", 0,  new StringBuilder());
	}

	public static int printSS(String quest, String ans) {
		if (quest.length() == 0) {
			System.out.println(ans);
			return 1;
		}

		char ch = quest.charAt(0);
		String roq = quest.substring(1);

		int cno = printSS(roq, ans); // no
		int cyes = printSS(roq, ans + ch); // yes

		return cno + cyes;
	}
	
	public static int printSSWithASb(String quest, int vidx, StringBuilder ans) {
		if (vidx == quest.length()) {
			System.out.println(ans);
			return 1;
		}

		char ch = quest.charAt(vidx);

		int cno = printSSWithASb(quest, vidx + 1, ans); // no
		
		ans.append(ch);
		int cyes = printSSWithASb(quest, vidx + 1, ans); // yes
		ans.deleteCharAt(ans.length() - 1);

		return cno + cyes;
	}


	public static ArrayList<String> getSS(String str) {
		if (str.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}

		char ch = str.charAt(0);
		String ros = str.substring(1);

		ArrayList<String> rr = getSS(ros);
		ArrayList<String> mr = new ArrayList<>();
		for (int i = 0; i < rr.size(); i++) {
			mr.add(rr.get(i));
			mr.add(ch + rr.get(i));
		}

		return mr;
	}

	public static void printSSWAscii(String quest, String ans) {
		if (quest.length() == 0) {
			System.out.println(ans);
			return;
		}

		char ch = quest.charAt(0);
		String roq = quest.substring(1);

		printSSWAscii(roq, ans); // no
		printSSWAscii(roq, ans + ch); // yes
		printSSWAscii(roq, ans + (int) ch); // yes, but as ascii
	}

	public static int printPermutations(String quest, String ans) {
		// System.out.println("Hi " + ans);
		if (quest.length() == 0) {
			System.out.println(ans);
			return 1;
		}

		int count = 0;

		for (int i = 0; i < quest.length(); i++) {
			char ch = quest.charAt(i);
			String roq = quest.substring(0, i) + quest.substring(i + 1);
			// System.out.println("Going the " + ch + " way from " + ans );
			int countCh = printPermutations(roq, ans + ch);
			count += countCh;
		}

		// System.out.println("Bye " + ans);

		return count;
	}

	public static int printKPC(String quest, String ans) {
		if (quest.length() == 0) {
			System.out.println(ans);
			return 1;
		}

		char ch = quest.charAt(0);
		String roq = quest.substring(1);
		String codes = getCode(ch);

		int count = 0;
		for (int i = 0; i < codes.length(); i++) {
			int countCH = printKPC(roq, ans + codes.charAt(i));
			count += countCH;
		}

		return count;
	}

	public static String getCode(char ch) {
		if (ch == '0') {
			return ".;";
		} else if (ch == '1') {
			return "abc";
		} else if (ch == '2') {
			return "def";
		} else if (ch == '3') {
			return "ghi";
		} else if (ch == '4') {
			return "jkl";
		} else if (ch == '5') {
			return "mno";
		} else if (ch == '6') {
			return "pqrs";
		} else if (ch == '7') {
			return "tuv";
		} else if (ch == '8') {
			return "wx";
		} else if (ch == '9') {
			return "yz";
		} else {
			return "";
		}
	}

	public static int printMPWD(int cr, int cc, int er, int ec, String ans) {
		if (cc == ec && cr == er) {
			System.out.println(ans);
			return 1;
		}

		if (cc > ec || cr > er) {
			return 0;
		}

		int count = 0;

		int ch = printMPWD(cr, cc + 1, er, ec, ans + "H");
		int cv = printMPWD(cr + 1, cc, er, ec, ans + "V");
		int cd = printMPWD(cr + 1, cc + 1, er, ec, ans + "D");

		count = ch + cv + cd;

		return count;
	}

	public static int printMPWDMS(int cr, int cc, int er, int ec, String ans) {
		if (cc == ec && cr == er) {
			System.out.println(ans);
			return 1;
		}

		if (cc > ec || cr > er) {
			return 0;
		}

		int count = 0;

		for (int moves = 1; moves <= ec - cc; moves++) {
			int ch = printMPWDMS(cr, cc + moves, er, ec, ans + "H" + moves);
			count += ch;
		}

		for (int moves = 1; moves <= er - cr; moves++) {
			int cv = printMPWDMS(cr + moves, cc, er, ec, ans + "V" + moves);
			count += cv;
		}

		for (int moves = 1; moves <= ec - cc && moves <= er - cr; moves++) {
			int cd = printMPWDMS(cr + moves, cc + moves, er, ec, ans + "D" + moves);
			count += cd;
		}

		return count;
	}

	public static int printBP(int curr, int end, String ans) {
		if (curr == end) {
			System.out.println(ans);
			return 1;
		}

		if (curr > end) {
			return 0;
		}

		int count = 0;

		for (int dice = 1; dice <= 6; dice++) {
			int cd = printBP(curr + dice, end, ans + dice);
			count += cd;
		}

		return count;
	}

	public static int printSSWithSumEqualToTarget(int[] arr, int vidx, int tar, 
												  String ans) {
		if (vidx == arr.length) {
			if (tar == 0) {
				System.out.println(ans);
				return 1;
			} else {
				return 0;
			}
		}

		int cno = printSSWithSumEqualToTarget(arr, vidx + 1, tar, ans);
		int cyes = printSSWithSumEqualToTarget(arr, vidx + 1, tar - arr[vidx], ans + " " + arr[vidx]);

		return cno + cyes;
	}

	public static int printSSEqualToComplement(int[] arr, int vidx, String group, String cgroup, int sge, int scge,
			boolean wasLastElementIncluded) {
		if (vidx == arr.length) {
			if (sge == scge) {
				System.out.println(group + " and " + cgroup);
				return 1;
			} else {
				return 0;
			}
		}

		if (wasLastElementIncluded == false) {
			int cyes = printSSEqualToComplement(arr, vidx + 1, group + " " + arr[vidx], cgroup, sge + arr[vidx], scge,
					true);
			int cno = printSSEqualToComplement(arr, vidx + 1, group, cgroup + " " + arr[vidx], sge, scge + arr[vidx],
					false);

			return cyes + cno;
		} else {
			int cno = printSSEqualToComplement(arr, vidx + 1, group, cgroup + " " + arr[vidx], sge, scge + arr[vidx],
					false);

			return cno;
		}
	}

	public static int printNQueens(boolean[][] board, int row, String ans) {
		if (row == board.length) {
			System.out.println(ans);
			return 1;
		}

		int count = 0;
		for (int col = 0; col < board.length; col++) {
			if (isitsafetoplacethequeen(board, row, col)) {
				board[row][col] = true;
				int cnt = printNQueens(board, row + 1, ans + "[" + row + "-" + col + "] ");
				count += cnt;
				board[row][col] = false;
			}
		}
		return count;
	}

	public static boolean isitsafetoplacethequeen(boolean[][] board, int row, int col) {
		int r = 0;
		int c = 0;

		// vertically up
		r = row;
		c = col;
		while (r >= 0) {
			if (board[r][c]) {
				return false;
			}
			r--;
		}

		// diagonal left
		r = row;
		c = col;
		while (r >= 0 && c >= 0) {
			if (board[r][c]) {
				return false;
			}

			r--;
			c--;
		}

		// diagonal right
		r = row;
		c = col;
		while (r >= 0 && c < board.length) {
			if (board[r][c]) {
				return false;
			}

			r--;
			c++;
		}

		return true;
	}

}

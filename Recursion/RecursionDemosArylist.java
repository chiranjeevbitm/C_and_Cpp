package june9;

import java.util.ArrayList;
import java.util.Arrays;

public class RecursionDemos {

	public static void main(String[] args) {
		// System.out.println(getKPC("182"));
		// System.out.println(getPermutations("abc"));
		// System.out.println(getBoardPaths(0, 10));
//		System.out.println(getMazePathsWDMS(0, 0, 2, 2));
		printLexico(1, 1000);
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

	public static ArrayList<String> getSSAscii(String str) {
		if (str.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}

		char ch = str.charAt(0);
		String ros = str.substring(1);

		ArrayList<String> rr = getSSAscii(ros);
		ArrayList<String> mr = new ArrayList<>();
		for (int i = 0; i < rr.size(); i++) {
			mr.add(rr.get(i));
			mr.add(ch + rr.get(i));
			mr.add((int) ch + rr.get(i));
		}

		return mr;
	}

	public static ArrayList<String> getKPC(String str) {
		if (str.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}

		char ch = str.charAt(0);
		String ros = str.substring(1);

		ArrayList<String> rr = getKPC(ros);
		ArrayList<String> mr = new ArrayList<>();

		String choices = getCode(ch);
		for (int i = 0; i < rr.size(); i++) {
			for (int j = 0; j < choices.length(); j++) {
				mr.add(choices.charAt(j) + rr.get(i));
			}
		}

		return mr;
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

	public static ArrayList<String> getPermutations(String str) {
		if (str.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}

		char ch = str.charAt(0);
		String ros = str.substring(1);

		ArrayList<String> rr = getPermutations(ros);
		ArrayList<String> mr = new ArrayList<>();

		for (int i = 0; i < rr.size(); i++) {
			String rrs = rr.get(i);
			StringBuilder sb = new StringBuilder(rrs);

			for (int j = 0; j <= rrs.length(); j++) {
				sb.insert(j, ch);
				mr.add(sb.toString());
				sb.deleteCharAt(j);
			}
		}

		return mr;
	}

	public static ArrayList<String> getBoardPaths(int curr, int end) {
		if (curr == end) {
			ArrayList<String> br = new ArrayList<>();
			br.add("\n");
			return br;
		}

		if (curr > end) {
			ArrayList<String> br = new ArrayList<>();
			return br;
		}

		ArrayList<String> mr = new ArrayList<>();

		for (int dice = 1; dice <= 6; dice++) {
			if (curr == 0) {
				if (dice == 1 || dice == 6) {
					ArrayList<String> rr = getBoardPaths(curr + dice, end);
					for (int i = 0; i < rr.size(); i++) {
						mr.add(dice + rr.get(i));
					}
				}
			} else {
				ArrayList<String> rr = getBoardPaths(curr + dice, end);
				for (int i = 0; i < rr.size(); i++) {
					mr.add(dice + rr.get(i));
				}
			}
		}

		return mr;
	}

	public static ArrayList<String> getMazePaths(int cr, int cc, int er, int ec) {
		if (cr == er && cc == ec) {
			ArrayList<String> br = new ArrayList<>();
			br.add("\n");
			return br;
		}

		if (cr > er || cc > ec) {
			ArrayList<String> br = new ArrayList<>();
			return br;
		}

		ArrayList<String> mr = new ArrayList<>();

		// horizontal
		ArrayList<String> rrh = getMazePaths(cr, cc + 1, er, ec);
		for (String rrsh : rrh) {
			mr.add("H" + rrsh);
		}

		// vertical
		ArrayList<String> rrv = getMazePaths(cr + 1, cc, er, ec);
		for (String rrsv : rrv) {
			mr.add("V" + rrsv);
		}

		return mr;
	}

	public static ArrayList<String> getMazePathsWD(int cr, int cc, int er, int ec) {
		if (cr == er && cc == ec) {
			ArrayList<String> br = new ArrayList<>();
			br.add("\n");
			return br;
		}

		if (cr > er || cc > ec) {
			ArrayList<String> br = new ArrayList<>();
			return br;
		}

		ArrayList<String> mr = new ArrayList<>();

		// horizontal
		ArrayList<String> rrh = getMazePathsWD(cr, cc + 1, er, ec);
		for (String rrsh : rrh) {
			mr.add("H" + rrsh);
		}

		// vertical
		ArrayList<String> rrv = getMazePathsWD(cr + 1, cc, er, ec);
		for (String rrsv : rrv) {
			mr.add("V" + rrsv);
		}

		// diagonal
		ArrayList<String> rrd = getMazePathsWD(cr + 1, cc + 1, er, ec);
		for (String rrsd : rrd) {
			mr.add("D" + rrsd);
		}

		return mr;
	}

	public static ArrayList<String> getMazePathsWDMS(int cr, int cc, int er, int ec) {
		if (cr == er && cc == ec) {
			ArrayList<String> br = new ArrayList<>();
			br.add("\n");
			return br;
		}

		if (cr > er || cc > ec) {
			ArrayList<String> br = new ArrayList<>();
			return br;
		}

		int moves = 0;
		ArrayList<String> mr = new ArrayList<>();

		// horizontal

		moves = 1;
		while (moves <= ec - cc) {
			ArrayList<String> rrh = getMazePathsWDMS(cr, cc + moves, er, ec);
			for (String rrsh : rrh) {
				mr.add("H" + moves + rrsh);
			}

			moves++;
		}

		// vertical
		moves = 1;
		while (moves <= er - cr) {
			ArrayList<String> rrv = getMazePathsWDMS(cr + moves, cc, er, ec);
			for (String rrsv : rrv) {
				mr.add("V" + moves + rrsv);
			}

			moves++;
		}

		// diagonal
		moves = 1;
		while (moves <= er - cr && moves <= ec - cc) {
			ArrayList<String> rrd = getMazePathsWDMS(cr + moves, cc + moves, er, ec);
			for (String rrsd : rrd) {
				mr.add("D" + moves + rrsd);
			}

			moves++;
		}

		return mr;
	}

	public static void printLexico(int curr, int max) {
		if (curr > max) {
			return;
		}

		// me
		System.out.println(curr);

		// and the numbers i am prefix of
		for (int i = 0; i <= 9; i++) {
			printLexico(10 * curr + i, max);
		}

		if (curr < 9) {
			printLexico(curr + 1, max);
		}
	}
}

package recursions;

import java.util.ArrayList;

public class printRecursion {

	public static void main(String[] args) {
		 printss("abac", "");
		// printssAscci("abc", "");
		// printPerm("abc", "");
		// printPermwithnodup("aac", "");
		// TossC(0, 4,"");
		// TossCnoConsH(0, 3, "", false);
		// printboardpath(0, 10, 0);
		// printlexico(1, 1000);
		// printlexico1(0, 1000);
		//int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
		//printTargetSS(arr, 5, 0, "");
		//int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
		// // System.out.println(find(arr, 8, 0));
		// int asn = printboardpath(0, 10, "");
		// System.out.println(asn);
		// printkpc("123", "");
		// printmazepathmm(0, 0, 2, 2, "");
		// System.out.println(Countmazepath(0, 0, 2, 2, ""));
		// printPermwithnodup1("aab", "");
		// printPermutationlexico("abc", "", false);
		// printsplitequal(arr, 0, 0, 0, "", "");
		// System.out.println(printTargetSS(arr, 6, 0, ""));
//		boolean[][] arr = new boolean[4][4];
//		arr[0][1] = true;
//		arr[1][3] = true;
//		arr[2][0] = true;
//		System.out.println(IsItSafeToPlace(3, 2, arr));
		//boolean[][] arr = new boolean[4][4];
//		arr[0][1] = true;
//		arr[1][3] = true;
//		arr[2][0] = true;
		
//
//		System.out.println(isitsafetoplacequeen(3, 2, arr));
	}

	public static void printss(String ques, String ans) {

		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}

		// calling
		char ch = ques.charAt(0); // no wali call
		String ros = ques.substring(1); // yes wali call

		printss(ros, ans + ch);
		printss(ros, ans);

	}

	public static void printssAscci(String ques, String ans) {

		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}

		// calling
		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		printssAscci(ros, ans);
		printssAscci(ros, ans + ch);
		printssAscci(ros, ans + (int) ch);

	}

	////////////////// problem
	public static void printPerm(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		// calling
		char ch = ques.charAt(0);
		String ros = ques.substring(1);

		for (int i = 0; i < ques.length(); i++) {
			StringBuilder sb = new StringBuilder(ques.charAt(i));
			for (int j = 0; j <= sb.length(); j++) {

				sb.insert(j, ch);

				ans = ans + (sb.toString());
				sb.deleteCharAt(j);
			}

		}

	}

	public static void printPermutation(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		// calling
		for (int i = 0; i < ques.length(); i++) {
			char ch = ques.charAt(i);
			String ros = ques.substring(0, i) + ques.substring(i + 1);
			printPermutation(ros, ans + ch);
		}
	}

	public static void printPermwithnodup(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		// calling
		boolean[] Isvisited = new boolean[256];

		for (int i = 0; i < ques.length(); i++) {
			char ch = ques.charAt(i);
			if (Isvisited[ch]) { /// doubt
				continue;

			}
			Isvisited[ch] = true;
			String ros = ques.substring(0, i) + ques.substring(i + 1);
			printPermwithnodup(ros, ans + ch);

		}
	}

	public static void printPermwithnodup1(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		// calling
		for (int i = 0; i < ques.length(); i++) {
			boolean flag = true;
			char ch = ques.charAt(i);
			for (int j = i + 1; j < ques.length(); j++) {
				if (ch == ques.charAt(j)) {
					flag = false;
					break;

				}
			}
			if (flag) {
				String ros = ques.substring(0, i) + ques.substring(i + 1);
				printPermwithnodup1(ros, ans + ch);
			}
		}
	}

	public static void printPermutationlexico(String ques, String ans, boolean Islarger) {
		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		// calling
		if (Islarger) {
			for (int i = 0; i < ques.length(); i++) {
				char ch = ques.charAt(i);
				String ros = ques.substring(0, i) + ques.substring(i + 1);

				printPermutationlexico(ros, ans + ch, true);

			}

		} else {
			for (int i = 0; i < ques.length(); i++) {
				char ch = ques.charAt(i);
				String ros = ques.substring(0, i) + ques.substring(i + 1);
				if (ch > ques.charAt(0)) {

					printPermutationlexico(ros, ans + ch, true);
				} else if (ch > ques.charAt(0)) {
					// no call
				} else {
					printPermutationlexico(ros, ans + ch, false);
				}
			}
		}
	}

	public static void TossC(int idx, int total, String ans) {
		// base case
		if (idx == total) {
			System.out.println(ans);
			return;
		}

		// calling

		TossC(idx + 1, total, ans + "H");
		TossC(idx + 1, total, ans + "T");

	}

	public static void TossCnoConsH(int idx, int total, String ans, boolean Isvisited) {
		// base case
		if (idx == total) {
			System.out.println(ans);
			return;
		}
		// calling
		if (Isvisited) {

			TossCnoConsH(idx + 1, total, ans + "T", false);

		} else {
			TossCnoConsH(idx + 1, total, ans + "H", true);
			TossCnoConsH(idx + 1, total, ans + "T", false);

		}

	}

	public static void TossCnoConsT(int idx, int total, String ans, boolean Isvisited) {
		// base case
		if (idx == total) {
			System.out.println(ans);
			return;
		}
		// calling
		if (Isvisited) {

			TossCnoConsT(idx + 1, total, ans + "H", false);

		} else {
			TossCnoConsT(idx + 1, total, ans + "T", true);
			TossCnoConsT(idx + 1, total, ans + "H", false);

		}

	}

	public static int printboardpath(int curr, int end, String ans) {
		// bases case
		if (curr == end) {

			System.out.println(ans);
			return 1;

		}

		if (curr > end) {

			return 0;
		}
		int count = 0;
		for (int dice = 1; dice <= 6; dice++) {

			int rr = printboardpath(curr + dice, end, ans + dice);
			count += rr;
		}
		return count;
	}

	public static void printlexico(int curr, int end) {
		// bases case
		if (curr == 0) {
			return;
		}
		if (curr > end) {
			return;
		}

		System.out.println(curr);
		for (int count = 0; count <= 9; count++) {
			printlexico(curr * 10 + count, end);
		}
		if (curr < 9) {
			printlexico(curr + 1, end);
		}

	}

	public static int Countlexico(int curr, int end) {
		// bases case
		if (curr == 0) {
			return 1;
		}
		if (curr > end) {
			return 0;
		}
		int r1 = 0;
		int r2 = 0;
		System.out.println(curr);
		for (int count = 0; count <= 9; count++) {
			r1 = Countlexico(curr * 10 + count, end);
		}
		if (curr < 9) {
			r2 = Countlexico(curr + 1, end);
		}
		return r1 + r2;

	}

	public static void printlexico1(int curr, int end) {
		// bases case

		if (curr > end) {
			return;
		}

		System.out.println(curr);

		if (curr == 0) {
			for (int count = 1; count <= 9; count++) {
				printlexico1(curr * 10 + count, end);
			}
		} else {
			for (int count = 0; count <= 9; count++) {
				printlexico1(curr * 10 + count, end);
			}
		}

	}

	// problem hai
	// public static int countlexico(int curr, int end) {
	// // bases case
	// if (curr == end) {
	// return 1;
	// }
	// if (curr > end) {
	//
	// // System.out.println();
	// return 0;
	//
	// }
	//
	// System.out.println(curr);
	// for (int count = 0; count <= 9; count++) {
	// int counter = countlexico(curr * 10 + count, end);
	//
	// }
	// if (curr < 9) {
	//
	// int counter1 = countlexico(curr + 1, end);
	//
	// }
	// return 0;
	//
	// }

	public static boolean find(int[] arr, int data, int vidx) {
		if (vidx == arr.length) {
			return false;

		}
		if (arr[vidx] == data) {
			return true;
		}

		return find(arr, data, vidx + 1);
	}

	public static boolean issorted(int[] arr, int vidx) {
		if (vidx == arr.length - 1) {
			return true;

		}
		if (arr[vidx] > arr[vidx + 1]) {
			return false;
		}
		boolean ans = issorted(arr, vidx + 1);
		return ans;
	}

	public static String kpc(char ch) {

		if (ch == '1')
			return "abc";
		else if (ch == '2')
			return "def";
		else if (ch == '3')
			return "ghi";
		else if (ch == '4')
			return "jk";
		else if (ch == '5')
			return "lmno";
		else if (ch == '6')
			return "pqr";
		else if (ch == '7')
			return "stu";
		else if (ch == '8')
			return "vwx";
		else if (ch == '9')
			return "yz";
		else if (ch == '0')
			return "@#";
		else
			return "";
	}

	public static void printkpc(String ques, String ans) {
		// bases case
		if (ques.length() == 0) {

			System.out.println(ans);
			return;

		}

		// call
		char ch = ques.charAt(0);
		String ros = ques.substring(1);

		String code = kpc(ch);

		for (int j = 0; j < code.length(); j++) {

			printkpc(ros, ans + code.charAt(j));
		}

	}

	public static void printmazepath(int scol, int srow, int ecol, int erow, String ans) {

		// bases case 2501
		if (scol == ecol && srow == erow) {

			System.out.println(ans);

			return;

		}

		if (scol > ecol || srow > erow) {
			// System.out.println(ans);

			return;
		}
		printmazepath(scol + 1, srow, ecol, erow, ans + "V");
		printmazepath(scol, srow + 1, ecol, erow, ans + "H");

	}

	public static int Countmazepath(int scol, int srow, int ecol, int erow, String ans) {

		// bases case 2501
		if (scol == ecol && srow == erow) {

			System.out.println(ans);

			return 1;

		}

		if (scol > ecol || srow > erow) {
			// System.out.println(ans);

			return 0;
		}
		int r1 = Countmazepath(scol + 1, srow, ecol, erow, ans + "V");
		int r2 = Countmazepath(scol, srow + 1, ecol, erow, ans + "H");
		return r1 + r2;

	}

	public static void printmazepathwD(int scol, int srow, int ecol, int erow, String ans) {

		// bases case 2501
		if (scol == ecol && srow == erow) {

			System.out.println(ans);

			return;

		}

		if (scol > ecol || srow > erow) {
			// System.out.println(ans);

			return;
		}
		printmazepathwD(scol + 1, srow, ecol, erow, ans + "V");
		printmazepathwD(scol, srow + 1, ecol, erow, ans + "H");
		printmazepathwD(scol + 1, srow + 1, ecol, erow, ans + "D");

	}

	public static void printmazepathmm(int scol, int srow, int ecol, int erow, String ans) {

		// bases case 2501
		if (scol == ecol && srow == erow) {

			System.out.println(ans);

			return;

		}

		if (scol > ecol || srow > erow) {
			// System.out.println(ans);

			return;
		}
		for (int i = 1; i <= ecol - scol; i++) {
			printmazepathmm(scol + 1, srow, ecol, erow, ans + "V");
		}
		for (int j = 1; j <= erow - srow; j++) {
			printmazepathmm(scol, srow + 1, ecol, erow, ans + "H");
		}
		for (int k = 1; k <= erow - srow && k < ecol - scol; k++) {
			printmazepathmm(scol + 1, srow + 1, ecol, erow, ans + "D");

		}

	}

	// public static void getQueueSum() {
	//
	// }

	public static int printTargetSS(int[] arr, int target, int vidx, String ans) {

		// base case
		if (arr.length == vidx) {
			if (target == 0) {
				System.out.println(ans);
				return 1;
			}
			return 0;
		}

		// call
		if (target < 0) {
			return 0;
		}
		int count = 0;
		int ansp = printTargetSS(arr, target - arr[vidx], vidx + 1, ans + arr[vidx]);
		count += ansp;
		int ansn = printTargetSS(arr, target, vidx + 1, ans);
		count += ansn;
		return count;
	}

	// public static void printTargetSSNoCS(int[] arr, int target, int vidx, String
	// ans) {
	//
	// // base case
	// if (arr.length == vidx) {
	// if (target == 0) {
	// System.out.println(ans);
	// }
	// return;
	// }
	//
	// // call
	// if (target < 0) {
	// return;
	// }
	//
	// boolean[] Isvisited = new boolean[256];
	//
	// for (int i = 0; i < arr.length; i++) {
	// int k = arr[i];
	// if (Isvisited[k]) { /// doubt
	// continue;
	//
	// }
	// Isvisited[k] = true;
	// printTargetSSNoCS(arr, target - arr[vidx], vidx + 1, ans + arr[vidx]);
	// printTargetSSNoCS(arr, target, vidx + 1, ans);
	//
	// }
	//
	// }
	public static void printsplitequal(int[] arr, int vidx, int gp1, int gp2, String gps1, String gps2) {
		// base case
		if (arr.length == vidx) {
			if (gp1 == gp2) {
				System.out.println("sums of -" + gps1 + "    =    " + "sums of-" + gps2);
			}
			return;
		}
		// calling

		printsplitequal(arr, vidx + 1, gp1 + arr[vidx], gp2, gps1 + " " + arr[vidx], gps2);
		printsplitequal(arr, vidx + 1, gp1, gp2 + arr[vidx], gps1, gps2 + " " + arr[vidx]);

	}

	public static boolean IsItSafeToPlace(int row, int col, boolean board[][]) {
		// vertically up call
		int rows = row;
		int cols = col;
		while (rows >= 0) {
			if (board[rows][cols]) {
				return false;
			}
			rows--;
		}
		// diagonally left call
		rows = row;
		cols = col;
		while (rows >= 0 && cols >= 0) {
			if (board[rows][cols]) {
				return false;
			}
			rows--;
			cols--;
		}
		
		// diagonally right call
		rows = row;
		cols = col;
		while (rows >= 0 && cols < board[0].length) {
			if (board[rows][cols]) {
				// System.out.println("diagonal right");
				return false;
			}

			rows--;
			cols++;
		}
		return true;
		
	}
	public static boolean isitsafetoplacequeen(int row, int col, boolean[][] board) {
		// vertically up
		int rows = row;
		int cols = col;
		while (rows >= 0) {
			if (board[rows][cols]) {
				// System.out.println("vertically up"+rows+" "+cols);
				return false;
			}

			rows--;
		}
		rows = row;
		cols = col;
		// diagonal left
		while (rows >= 0 && cols >= 0) {
			if (board[rows][cols]) {
				// System.out.println("diagonal left");
				return false;
			}

			rows--;
			cols--;
		}
		// diagonal right
		rows = row;
		cols = col;
		while (rows >= 0 && cols < board[0].length) {
			if (board[rows][cols]) {
				// System.out.println("diagonal right");
				return false;
			}

			rows--;
			cols++;
		}
		return true;
	}

}

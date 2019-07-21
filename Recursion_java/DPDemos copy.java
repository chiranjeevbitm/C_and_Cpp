package june23;

public class DPDemos {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// System.out.println(lcsIterative("abefg", "aefdg"));
		// System.out.println(edIterative("ecfjk", "bcdfk"));

		int[] prices = { 20, 25, 35, 25 };
		int[] weights = { 10, 20, 30, 15 };
		// System.out.println(knapSackTD(prices, weights, 0, 50, 0, "", new
		// int[prices.length + 1][51]));
		// System.out.println(knapSackBU(prices, weights, 0, 50, new
		// int[prices.length + 1][51]));

		printLexicoGreater("bcad", "", false);
	}

	public static int lcsIterative(String s1, String s2) {
		int[][] strg = new int[s1.length() + 1][s2.length() + 1];

		for (int row = s1.length() - 1; row >= 0; row--) {
			for (int col = s2.length() - 1; col >= 0; col--) {
				if (s1.charAt(row) == s2.charAt(col)) {
					strg[row][col] = 1 + strg[row + 1][col + 1];
				} else {
					strg[row][col] = Math.max(strg[row + 1][col], strg[row][col + 1]);
				}
			}
		}

		return strg[0][0];

		// int[] strg = new int[s2.length() + 1];
		//
		//
		// for(int slide = 1; slide <= s1.length(); slide++){
		// int diag = 0;
		// for(int col = s2.length() - 1; col >= 0; col--){
		// int nv = 0;
		//
		// if(s1.charAt(s1.length() - slide) == s2.charAt(col)){
		// nv = diag + 1;
		// } else {
		// nv = Math.max(strg[col], strg[col + 1]);
		// }
		//
		// diag = strg[col];
		// strg[col] = nv;
		//
		// }
		// }
		//
		// return strg[0];
	}

	public static int editDistance(String s1, String s2) {
		if (s1.length() == 0) {
			return s2.length(); // removals
		}

		if (s2.length() == 0) {
			return s1.length(); // insertion
		}

		char ch1 = s1.charAt(0);
		String ros1 = s1.substring(1);

		char ch2 = s2.charAt(0);
		String ros2 = s2.substring(1);

		if (ch1 == ch2) {
			return editDistance(ros1, ros2);
		} else {
			// int f1 = editDistance(s1, ch1 + s2) + 1;
			// int f2 = editDistance(s1, ch1 + ros2) + 1;

			// insertion
			int f1 = editDistance(ros1, s2) + 1;

			// replacement
			int f2 = editDistance(ros1, ros2) + 1;

			// removal
			int f3 = editDistance(s1, ros2) + 1;

			return Math.min(f1, Math.min(f2, f3));
		}

	}

	public static int edIterative(String s1, String s2) {
		int[][] strg = new int[s1.length() + 1][s2.length() + 1];

		for (int row = s1.length(); row >= 0; row--) {
			for (int col = s2.length(); col >= 0; col--) {
				if (row == s1.length()) {
					strg[row][col] = s2.length() - col;
					continue;
				}

				if (col == s2.length()) {
					strg[row][col] = s1.length() - row;
					continue;
				}

				if (s1.charAt(row) == s2.charAt(col)) {
					strg[row][col] = strg[row + 1][col + 1];
				} else {
					int fin = strg[row + 1][col];
					int frp = strg[row + 1][col + 1];
					int frm = strg[row][col + 1];

					strg[row][col] = 1 + Math.min(fin, Math.min(frp, frm));
				}
			}
		}

		return strg[0][0];
	}

	public static int knapSackBU(int[] prices, int[] weights, int vidx, int cap, int[][] strg) {
		if (vidx == prices.length) {
			return 0;
		}

		if (strg[vidx][cap] != 0) {
			return strg[vidx][cap];
		}

		int f1 = 0;

		if (weights[vidx] <= cap) {
			f1 = prices[vidx] + knapSackBU(prices, weights, vidx + 1, cap - weights[vidx], strg);
		}

		int f2 = 0 + knapSackBU(prices, weights, vidx + 1, cap, strg);

		int rv = Math.max(f1, f2);

		strg[vidx][cap] = rv;
		return rv;
	}

	public static int knapSackTD(int[] prices, int[] weights, int vidx, int cap, int vsf, String asf, int[][] strg) {
		if (vidx == prices.length) {
			return vsf;
		}

		if (strg[vidx][cap] != 0) {
			return strg[vidx][cap];
		}

		int f1 = 0;

		int f2 = knapSackTD(prices, weights, vidx + 1, cap, vsf, asf, strg);

		if (weights[vidx] <= cap) {
			f1 = knapSackTD(prices, weights, vidx + 1, cap - weights[vidx], vsf + prices[vidx], asf + " " + vidx, strg);
		}

		int rv = Math.max(f1, f2);

		strg[vidx][cap] = rv;
		return rv;
	}

	public static void printLexicoGreater(String quest, String ans, boolean isAlreadyGreater) {
		if (quest.length() == 0) {
			if (isAlreadyGreater) {
				System.out.println(ans);
			}
			return;
		}

		if (isAlreadyGreater) {
			for (int i = 0; i < quest.length(); i++) {
				char ch = quest.charAt(i);
				String ros = quest.substring(0, i) + quest.substring(i + 1);
				printLexicoGreater(ros, ans + ch, true);
			}
		} else {
			for (int i = 0; i < quest.length(); i++) {
				char ch = quest.charAt(i);
				String ros = quest.substring(0, i) + quest.substring(i + 1);

				if (ch > quest.charAt(0)) {
					printLexicoGreater(ros, ans + ch, true);
				} else if (ch == quest.charAt(0)) {
					printLexicoGreater(ros, ans + ch, false);
				} else {

				}
			}
		}
	}

}

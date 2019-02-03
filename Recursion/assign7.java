package recursions;

import java.net.StandardSocketOptions;

public class assign7 {
	public static void main(String args[]) {
		// System.out.println(sumOfnumS("123", 0,0));
		// System.out.println(strtoint("13423", 0,0));

		// System.out.println(checkrev("abcdef", "fedcba", 0,0));
		// System.out.println(placestar("hello", ""));
		// System.out.println(removedup("hello", ""));
		// System.out.println(sepx("abexexdexed", "", ""));
		// counthi("ihihieihiohiwwhihihihii", 0, 0);
		// counthiskip("hihehillohit", 0, 0);
		// System.out.println(removehiskip("hihehillohithihihit", "", 0));
		// System.out.println(replacehiskip("hihehillohithihihit", "", 0));
		//printcode("1123", "");
		 printcodebtr("1123", "");
	}

	public static void sumOfnumI(int ques, int ans) {
		// base case
		if (ques == 0) {
			System.out.println(ans);
			return;
		}
		// calling part
		sumOfnumI(ques / 10, ans + (ques % 10));

	}

	public static int sumOfnumS(String ques, int ans, int vidx) {
		// base case
		if (vidx == ques.length()) {

			return ans;
		}
		// calling part

		int result = sumOfnumS(ques, (ans + ques.charAt(vidx)) - 48, vidx + 1);
		return result;

	}

	public static int strtoint(String ques, int ans, int vidx) {
		// base case
		if (vidx == ques.length()) {

			return ans;
		}

		// calling part

		return strtoint(ques, ans + ((ques.charAt(vidx)) - 48) * (int) Math.pow(10, ques.length() - vidx - 1),
				vidx + 1);

	}

	public static boolean checkrev(String str1, String str2, int vidx1, int vidx2) {
		// base case
		if (str1.length() != str2.length()) {
			return false;
		}
		if (vidx1 == str1.length() && vidx2 == str2.length()) {
			return true;
		}

		// calling
		if (str1.charAt(vidx1) != str2.charAt(str2.length() - vidx2 - 1)) {
			return false;
		}

		return checkrev(str1, str2, vidx1 + 1, vidx2 + 1);

	}

	public static String placestar(String ques, String ans) {
		// base case

		if (ques.length() == 0) {

			return ans;
		}
		// calling part
		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		if (ros.length() != 0 && ch == ros.charAt(0)) {
			return placestar(ros, ans + ch + "*");
		} else {
			return placestar(ros, ans + ch);
		}

	}

	public static String removedup(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			return ans;
		}

		// calling
		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		if (ros.length() != 0 && ch == ros.charAt(0)) {
			return removedup(ros, ans);
		} else {
			return removedup(ros, ans + ch);
		}

	}

	public static String sepx(String ques, String ans, String forx) {
		// base case
		if (ques.length() == 0) {
			return ans + forx;
		}

		// calling
		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		if (ros.length() != 0 && ch == 'x') {
			return sepx(ros, ans, forx + ch);

		} else {
			return sepx(ros, ans + ch, forx);
		}

	}

	public static void counthi(String ques, int ans, int vidx) {
		// base case
		if (vidx == ques.length()) {
			System.out.println(ans);
			return;
		}

		// calling
		if (ques.charAt(vidx) == 'h' && ques.charAt(vidx + 1) == 'i') {

			counthi(ques, ans + 1, vidx + 1);
		} else {
			counthi(ques, ans, vidx + 1);
		}

	}

	public static String removehi(String ques, String ans, int vidx) {
		// base case
		if (vidx == ques.length()) {
			// System.out.println(ans);
			return ans;
		}

		// calling
		if (vidx != ques.length() && ques.charAt(vidx) == 'h' && ques.charAt(vidx + 1) == 'i') {

			return removehi(ques, ans, vidx + 2);
		} else {
			return removehi(ques, ans + ques.charAt(vidx), vidx + 1);
		}

	}

	public static String replacehi(String ques, String ans, int vidx) {
		// base case
		if (vidx == ques.length()) {
			// System.out.println(ans);
			return ans;
		}

		// calling
		if (vidx != ques.length() && ques.charAt(vidx) == 'h' && ques.charAt(vidx + 1) == 'i') {

			return replacehi(ques, ans + "bye", vidx + 2);
		} else {
			return replacehi(ques, ans + ques.charAt(vidx), vidx + 1);
		}

	}

	public static String removehiskip(String ques, String ans, int vidx) {
		// base case
		if (vidx == ques.length()) {
			// System.out.println(ans);
			return ans;
		}

		// calling
		if (vidx != ques.length() && ques.charAt(vidx) == 'h' && ques.charAt(vidx + 1) == 'i'
				&& ques.charAt(vidx + 2) != 't') {

			return removehiskip(ques, ans, vidx + 2);

		} else {
			return removehiskip(ques, ans + ques.charAt(vidx), vidx + 1);
		}

	}

	public static String replacehiskip(String ques, String ans, int vidx) {
		// base case
		if (vidx == ques.length()) {
			// System.out.println(ans);
			return ans;
		}

		// calling
		if (vidx != ques.length() && ques.charAt(vidx) == 'h' && ques.charAt(vidx + 1) == 'i'
				&& ques.charAt(vidx + 2) != 't') {

			return replacehiskip(ques, ans + "bye", vidx + 2);

		} else {
			return replacehiskip(ques, ans + ques.charAt(vidx), vidx + 1);
		}

	}

	public static void printcode(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		String ros1 = ques.substring(1);
		char ch = ques.charAt(0);
		char additem1 = (char) (ch + 48);
		String ros2 = ques.substring(2);
		String st2 = ques.substring(0, 2);
		int a = Integer.parseInt(st2);
		if (a > 26) {
			return;
		}
		char additem2 = (char) (a + 48);

		// calling
		printcode(ros1, ans + additem1);
		printcode(ros2, ans + additem2);

	}
	public static void printcodebtr(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		String ch01 = ques.substring(0,1);
		String ros1 = ques.substring(1);

		char code = (char)(Integer.parseInt(ch01)+'a'-1);
		printcodebtr(ros1, ans+code);

		if(ques.length()>=2) {
			String ch02 = ques.substring(0,2);
			String ros2 = ques.substring(2);

			if(Integer.parseInt(ch02)<=26) {
			code = (char)(Integer.parseInt(ch02)+'a'-1);
			printcodebtr(ros2, ans+ code);
			}
		}

	}
}

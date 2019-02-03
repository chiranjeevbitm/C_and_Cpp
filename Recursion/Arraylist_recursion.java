package recursions;

import java.util.ArrayList;
import java.util.Scanner;

public class Arraylist_recursion {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		// System.out.println(getss("abc"));
		// ArrayList<String> mm = getkpc("123");
		// System.out.println(mm);
		// System.out.println(mm.size());
		// ArrayList<String> mm = getboardpath(0, 11);
		// System.out.println(mm.size());

           ArrayList<String> mp = getmazepathwD(0, 0, 2, 2);
		   System.out.println(mp);
		// ArrayList<String> mp = getssmulticall("abc", "");
		// System.out.println(mp);
	}

	public static ArrayList<String> getss(String ques) {
		// base case
		if (ques.length() == 0) {
			ArrayList<String> mr = new ArrayList<>();
			mr.add("");
			return mr;

		}

		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		ArrayList<String> rr = getss(ros);

		ArrayList<String> mr = new ArrayList<>();
		for (int i = 0; i < rr.size(); i++) {

			mr.add(rr.get(i));
			mr.add(ch + rr.get(i));

		}
		return mr;

	}

	public static ArrayList<String> getsswithAscci(String ques) {
		// base case
		if (ques.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;

		}

		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		ArrayList<String> rr = getsswithAscci(ros);

		ArrayList<String> mr = new ArrayList<>();
		for (int i = 0; i < rr.size(); i++) {

			mr.add(rr.get(i));
			mr.add(ch + rr.get(i));
			int ch1 = ch;
			mr.add(ch1 + rr.get(i));

		}
		return mr;

	}

	public static String printkpc(char ch) {

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

	public static ArrayList<String> getkpc(String ques) {
		// bases case
		if (ques.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;

		}

		// call
		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		ArrayList<String> rr = getkpc(ros);
		String code = printkpc(ch);
		ArrayList<String> mm = new ArrayList<>();
		for (int i = 0; i < rr.size(); i++) {
			String ans = rr.get(i);
			for (int j = 0; j < code.length(); j++) {
				mm.add(code.charAt(j) + ans);
			}
		}
		return mm;
	}

	public static ArrayList<String> getpermutation(String ques) {
		// bases case
		if (ques.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;

		}

		// call
		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		ArrayList<String> rr = getpermutation(ros);
		// String code = printkpc(ch);
		ArrayList<String> mm = new ArrayList<>();
		for (int i = 0; i < rr.size(); i++) {
			StringBuilder sb = new StringBuilder(rr.get(i));
			for (int j = 0; j <= sb.length(); j++) {
				sb.insert(j, ch);
				mm.add(sb.toString());
				sb.deleteCharAt(j);
			}
		}
		return mm;
	}

	public static ArrayList<String> getboardpath(int curr, int end) {
		// bases case
		if (curr == end) {
			ArrayList<String> br = new ArrayList<>();
			br.add(" ");
			return br;

		}
		ArrayList<String> mm = new ArrayList<>();
		if (curr > end) {
			ArrayList<String> br = new ArrayList<>();
			// br.add("");
			return br;
		}
		for (int dice = 1; dice <= 6; dice++) {
			ArrayList<String> rr = getboardpath(curr + dice, end);
			// mm.add(dice+rr.get(index))
			for (int i = 0; i < rr.size(); i++) {
				mm.add(dice + rr.get(i));
			}
		}
		return mm;
	}

	public static ArrayList<String> getmazepath(int scol, int srow, int ecol, int erow) {

		// bases case 2501
		if (scol == ecol && srow == erow) {
			ArrayList<String> br = new ArrayList<>();
			br.add(" ");
			return br;

		}
		ArrayList<String> mm = new ArrayList<>();
		if (scol > ecol || srow > erow) {
			ArrayList<String> br = new ArrayList<>();
			// br.add("");
			return br;
		}
		// hor call
		ArrayList<String> rr = getmazepath(scol + 1, srow, ecol, erow);
		for (int i = 0; i < rr.size(); i++) {
			mm.add("H" + rr.get(i));
		}
		ArrayList<String> mr = getmazepath(scol, srow + 1, ecol, erow);
		for (int i = 0; i < mr.size(); i++) {
			mm.add("V" + mr.get(i));
		}
		
		return mm;
	}

	public static ArrayList<String> getmazepathwD(int scol, int srow, int ecol, int erow) {

		// bases case 2501
		if (scol == ecol && srow == erow) {
			ArrayList<String> br = new ArrayList<>();
			br.add(" ");
			return br;

		}
		ArrayList<String> mm = new ArrayList<>();
		if (scol > ecol || srow > erow) {
			ArrayList<String> br = new ArrayList<>();
			// br.add("");
			return br;
		}
		// hor call
		ArrayList<String> rr = getmazepathwD(scol + 1, srow, ecol, erow);
		for (int i = 0; i < rr.size(); i++) {
			mm.add("H" + rr.get(i));
		}
		ArrayList<String> mr = getmazepathwD(scol, srow + 1, ecol, erow);
		for (int i = 0; i < mr.size(); i++) {
			mm.add("V" + mr.get(i));
		}
		ArrayList<String> dr = getmazepathwD(scol + 1, srow + 1, ecol, erow);
		for (int i = 0; i < dr.size(); i++) {
			mm.add("D" + dr.get(i));
		}

		return mm;
	}

	
	//problem hai........................
//	............
	public static ArrayList<String> getmazepathmm(int scol, int srow, int ecol, int erow) {

		// bases case 2501
		if (scol == ecol && srow == erow) {
			ArrayList<String> br = new ArrayList<>();
			br.add(" ");
			return br;

		}
		if (scol > ecol || srow > erow) {
			ArrayList<String> br = new ArrayList<>();
			// br.add("");
			return br;
		}
		// horizontal call
		ArrayList<String> mm = new ArrayList<>();
		for (int move = 1; move <=ecol - scol; move++) {

			ArrayList<String> rr1 = getmazepathmm(scol + move, srow, ecol, erow);
			for (int i = 0; i < rr1.size(); i++) {
				mm.add("V" + move + rr1.get(i));
			}
		}
		for (int move = 1; move <= erow - srow; move++) {
			ArrayList<String> rr2 = getmazepathmm(scol, srow + move, ecol, erow);
			for (int j = 0; j < rr2.size(); j++) {
				mm.add("H" + move + rr2.get(j));
			}
		}
		for (int move = 1; move <= erow - srow && move <= ecol - scol; move++) {
			ArrayList<String> rr3 = getmazepathmm(scol + move, srow + move, ecol, erow);
			for (int k = 0; k < rr3.size(); k++) {
				mm.add("D" + move + rr3.get(k));
			}
		}

		return mm;
	}

	public static ArrayList<String> getssmulticall(String ques, String ans) {
		// base case
		if (ques.length() == 0) {
			ArrayList<String> mr = new ArrayList<>();
			mr.add(ans);
			return mr;

		}

		char ch = ques.charAt(0);
		String ros = ques.substring(1);
		// ArrayList<String> rr = getssmulticall(ros,ans);

		ArrayList<String> rr = new ArrayList<>();
		ArrayList<String> mr1 = getssmulticall(ros, ans + ch);
		ArrayList<String> mr2 = getssmulticall(ros, ans);
		rr.addAll(mr2);
		rr.addAll(mr1);
		return rr;

	}
	

}
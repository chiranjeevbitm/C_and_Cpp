package june13extra;

import java.util.ArrayList;

public class RecursionDemos {

	public static void main(String[] args) {
		// System.out.println(getEquiSum("abcdefgh", "", "", 0, 0));
		// System.out.println(getPermuations("aabb", ""));
		System.out.println(getMPWithDiagMS(0, 0, 3, 3));
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

	public static ArrayList<String> getSSAnotherWay(String str, String ssf) {
		if (str.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add(ssf);
			return br;
		}

		char ch = str.charAt(0);
		String ros = str.substring(1);

		ArrayList<String> mr = new ArrayList<>();

		ArrayList<String> rrNeg = getSSAnotherWay(ros, ssf + "");
		mr.addAll(rrNeg);

		ArrayList<String> rrPos = getSSAnotherWay(ros, ssf + ch);
		mr.addAll(rrPos);

		return mr;
	}

	public static ArrayList<String> getEquiSum(String str, String g1, String g2, int sg1, int sg2) {
		if (str.length() == 0) {
			ArrayList<String> br = new ArrayList<>();

			if (sg1 == sg2) {
				br.add(g1 + " and " + g2 + ".\n");
			}

			return br;
		}

		char ch = str.charAt(0);
		String ros = str.substring(1);

		ArrayList<String> mr = new ArrayList<>();

		ArrayList<String> rrg1 = getEquiSum(ros, g1 + ch, g2, sg1 + ch, sg2);
		mr.addAll(rrg1);

		ArrayList<String> rrg2 = getEquiSum(ros, g1, g2 + ch, sg1, sg2 + ch);
		mr.addAll(rrg2);

		return mr;
	}

	public static ArrayList<String> getPermuations(String quest, String asf) {
		if (quest.length() == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add(asf);
			return br;
		}

		ArrayList<String> mr = new ArrayList<>();
		boolean[] dupli = new boolean[256];

		for (int i = 0; i < quest.length(); i++) {
			char ch = quest.charAt(i);
			if (dupli[ch] == true) {
				continue;
			}

			String ros = quest.substring(0, i) + quest.substring(i + 1);

			ArrayList<String> rr = getPermuations(ros, asf + ch);
			mr.addAll(rr);

			dupli[ch] = true;
		}

		return mr;
	}

	public static ArrayList<String> getMPWithDiag(int cr, int cc, int er, int ec) {
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

		ArrayList<String> rrh = getMPWithDiag(cr, cc + 1, er, ec);
		for (int i = 0; i < rrh.size(); i++) {
			mr.add("H" + rrh.get(i));
		}

		ArrayList<String> rrv = getMPWithDiag(cr + 1, cc, er, ec);
		for (int i = 0; i < rrv.size(); i++) {
			mr.add("V" + rrv.get(i));
		}

		ArrayList<String> rrd = getMPWithDiag(cr + 1, cc + 1, er, ec);
		for (int i = 0; i < rrd.size(); i++) {
			mr.add("D" + rrd.get(i));
		}

		return mr;
	}

	public static ArrayList<String> getMPWithDiagMS(int cr, int cc, int er, int ec) {
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

		for (int i = 1; i <= ec - cc; i++) {
			ArrayList<String> rrh = getMPWithDiagMS(cr, cc + i, er, ec);
			for (int ii = 0; ii < rrh.size(); ii++) {
				mr.add("H" + i + rrh.get(ii));
			}
		}

		for (int i = 1; i <= er - cr; i++) {
			ArrayList<String> rrv = getMPWithDiagMS(cr + i, cc, er, ec);
			for (int ii = 0; ii < rrv.size(); ii++) {
				mr.add("V" + i + rrv.get(ii));
			}
		}

		for (int i = 1; i <= er - cr &&  i <= ec - cc; i++) {
			ArrayList<String> rrd = getMPWithDiagMS(cr + i, cc + i, er, ec);
			for (int ii = 0; ii < rrd.size(); ii++) {
				mr.add("D" + i + rrd.get(ii));
			}
		}

		return mr;
	}

	public static boolean IsPalindrome(int[] arr, int left, int right){
		
		if(arr[left] != arr[right]){
			return false;
		}
		
		boolean issapal = IsPalindrome(arr, left + 1, right - 1);
		return issapal;
		
	}
}

package june8;

import java.util.ArrayList;

public class RecursionDemos {

	public static void main(String[] args) {
		// PrintDISkip(5);

		// System.out.println(PowerBtr(3, 4));
		// System.out.println(Fibonnaci(10));
		// PrintRows(1, 5);

		// PrintTriangle(1, 1, 5);

		// System.out.println(find(new int[] {55, 11, 20, 2, 18}, 22));
		// displayReverse(new int[] {55, 11, 20, 2, 18}, 0);
//		System.out.println(max(new int[] { 5, 11, 20, 2, 18 }, 0));
//		int[] ai = allindices(new int[] {12, 18, 9, 10, 27, 16, 10, 26, 10, 15}, 10, 0, 0);
//		display(ai);

//		int[] arr = {12, 18, 9, 10, 27, 16, 10, 26, 10, 15};
//		bubbleSort(arr, 0, arr.length - 1);
//		display(arr);

		int[] one = {1, 1, 2, 2, 2, 3, 5};
		int[] two = {1, 1, 1, 2, 2, 4, 5};
		ArrayList<Integer> list = getIntersection(one, two);
		System.out.println(list);
		
		for(int val: list){
			System.out.println(val);
		}

		for(int i = 0; i < list.size(); i++){
			System.out.println(list.get(i));
		}
	}

	public static void PrintDecreasing(int num) {
		if (num == 0) {
			return;
		}

		System.out.println(num);
		PrintDecreasing(num - 1);
	}

	public static void PrintIncreasing(int num) {
		if (num == 0) {
			return;
		}

		PrintIncreasing(num - 1);
		System.out.println(num);
	}

	public static void PrintDI(int num) {
		if (num == 0) {
			return;
		}

		System.out.println(num);
		PrintDI(num - 1);
		System.out.println(num);
	}

	public static void PrintDISkip(int num) {
		if (num == 0) {
			return;
		}

		if (num % 2 == 1) {
			System.out.println(num);
		}

		PrintDISkip(num - 1);

		if (num % 2 == 0) {
			System.out.println(num);
		}
	}

	public static int Factorial(int num) {
		if (num == 0) {
			return 1;
		}

		int fnm1 = Factorial(num - 1);
		int fn = num * fnm1;

		return fn;
	}

	public static int Power(int x, int n) {
		if (n == 0) {
			return 1;
		}

		int xpnm1 = Power(x, n - 1);
		int xpn = xpnm1 * x;

		return xpn;
	}

	public static int PowerBtr(int x, int n) {
		if (n == 0) {
			return 1;
		}

		int xpnb2 = PowerBtr(x, n / 2);
		int xpn = xpnb2 * xpnb2;

		if (n % 2 == 1) {
			xpn = xpn * x;
		}

		return xpn;
	}

	public static int Fibonnaci(int n) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}

		int fibnm1 = Fibonnaci(n - 1);
		int fibnm2 = Fibonnaci(n - 2);
		int fibn = fibnm1 + fibnm2;

		return fibn;
	}

	public static void PrintColumns(int col, int n) {
		if (col > n) {
			return;
		}

		System.out.print("*");
		PrintColumns(col + 1, n);
	}

	public static void PrintRows(int row, int n) {
		if (row > n) {
			return;
		}

		System.out.println("~~~~~~~~~~~~~~~~~~~~");
		PrintRows(row + 1, n);
	}

	public static void PrintBox(int row, int col, int n) {
		if (row > n) {
			return;
		}

		if (col > n) {
			System.out.println();
			PrintBox(row + 1, 1, n);
			return;
		}

		System.out.print("*");
		PrintBox(row, col + 1, n);
	}

	public static void PrintTriangle(int row, int col, int n) {
		if (row > n) {
			return;
		}

		if (col > row) {
			PrintTriangle(row + 1, 1, n);
			System.out.println();
			return;
		}

		PrintTriangle(row, col + 1, n);
		System.out.print("*");
	}

	public static int find(int[] arr, int data) {
		if (arr.length == 0) {
			return -1;
		}

		if (arr[0] == data) {
			return 0;
		}

		int[] sa = new int[arr.length - 1];
		for (int i = 0; i < sa.length; i++) {
			sa[i] = arr[i + 1];
		}

		int foundInSaAt = find(sa, data);

		if (foundInSaAt == -1) {
			return -1;
		} else {
			return foundInSaAt + 1;
		}
	}

	public static void display(int[] arr) {
		if (arr.length == 0) {
			return;
		}

		System.out.println(arr[0]);

		int[] sa = new int[arr.length - 1];
		for (int i = 0; i < sa.length; i++) {
			sa[i] = arr[i + 1];
		}

		display(sa);
	}

	public static void display(int[] arr, int vidx) {
		if (vidx == arr.length) {
			return;
		}

		System.out.println(arr[vidx]);
		display(arr, vidx + 1);
	}

	public static void displayReverse(int[] arr, int vidx) {
		if (vidx == arr.length) {
			return;
		}

		displayReverse(arr, vidx + 1);
		System.out.println(arr[vidx]);
	}

	public static int max(int[] arr, int vidx) {
		if (vidx == arr.length - 1) {
			return arr[vidx];
		}

		int maxInSa = max(arr, vidx + 1);
		if (maxInSa > arr[vidx]) {
			return maxInSa;
		} else {
			return arr[vidx];
		}
	}

	public static int[] allindices(int[] arr, int data, int vidx, int fsf) {
		if (vidx == arr.length) {
			return new int[fsf];
		}

		int[] rr = null;

		if (arr[vidx] == data) {
			rr = allindices(arr, data, vidx + 1, fsf + 1);
			rr[fsf] = vidx;

		} else {
			rr = allindices(arr, data, vidx + 1, fsf);
		}

		return rr;

	}

	public static void bubbleSort(int[] arr, int si, int li){
		if(li == 0){
			return;
		}

		if(si == li){
			bubbleSort(arr, 0, li - 1);
			return;
		}

		if(arr[si] > arr[si + 1]){
			int temp = arr[si];
			arr[si] = arr[si + 1];
			arr[si + 1] = temp;
		}

		bubbleSort(arr, si + 1, li);
	}

	public static ArrayList<Integer> getIntersection(int[] one, int[] two){
		ArrayList<Integer> rv = new ArrayList<>();

		int i = 0, j = 0;
		while(i < one.length && j < two.length){
			if(one[i] < two[j]){
				i++;
			} else if (one[i] > two[j]){
				j++;
			} else {
				rv.add(one[i]);
				i++;
				j++;
			}
		}

		return rv;
	}

}

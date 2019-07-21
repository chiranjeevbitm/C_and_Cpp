package recursions;

//import java.util.ArrayList;

public class Recursion1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// System.out.println(fact(2));
		// printinc(5);
		// printdecincskip(5);
		// System.out.println(printpowerbetter(3,5));
		int[] arr = { 5,4,3,2,1 };
		//display(arr, 0);
		//triangle(5);
		//triangleInvers(0,0,5);
		//vindex(arr, 0);
		//System.out.println(find(arr, 0, 1));
       //int[]r= findallindex(arr, 11, 0, 0);
       // display(r, 0);
		
		bubblesort(arr, 0, arr.length-1);
		display(arr, 0);
	}
 
	public static int fact(int num) {

		// base case
		if (num == 0) {
			return 1;
		}

		// calling part
		int pans = fact(num - 1);
		int fac = pans * num;
		return fac;

	}

	public static void printdec(int num) {
		// base case
		if (num == 0) {
			return;
		}

		// calling part
		System.out.println(num);
		printdec(num - 1);

	}

	public static void printinc(int num) {
		// base case

		if (num == 0) {
			return;
		}

		// calling part

		printinc((num - 1));
		System.out.println(num);
		return;

	}

	public static void printdecinc(int num) {
		// base case

		if (num == 0) {
			return;
		}

		// calling part

		System.out.println(num);
		printdecinc((num - 1));

		System.out.println(num);

	}

	public static void printdecincskip(int num) {
		// base case

		if (num == 0) {
			return;
		}

		// calling part
		if (num % 2 != 0) {
			System.out.println(num);

		}

		printdecincskip((num - 1));

		if (num % 2 == 0) {
			System.out.println(num);
		}
	}

	public static int printpower(int num, int pow) {
		// base case

		if (pow == 0) {
			return 1;
		}

		// calling part
		int pans = printpower(num, pow - 1);
		int ans = pans * num;
		return ans;
		// return printpower(num, pow-1)*num;
	}

	public static int printpowerbetter(int num, int pow) {
		// base case

		if (pow == 0) {
			return 1;
		}

		// calling part
		int pans = printpowerbetter(num, pow / 2);
		if (pow % 2 == 0) {
			return pans * pans;
		} else {

			return pans * pans * num;
		}
		// return printpower(num, pow-1)*num;
	}

	public static int printfibbonaci(int num) {
		// base case

		if (num == 0) {
			return 0;
		}
		if (num == 1) {
			return 1;
		}

		// calling part
		int ans1 = printfibbonaci(num - 1);

		int ans2 = printfibbonaci(num - 2);
		return ans1 + ans2;
		// return printpower(num, pow-1)*num;
	}

	public static void printstarcol(int col, int num) {
		// base case
		if (col > num) {
			return;
		}

		// calling part
		printstarcol(col + 1, num);
		System.out.print("* ");

	}

	public static void printstarrow(int row, int num) {
		// base case
		if (row > num) {
			return;
		}

		// calling part
		printstarrow(row + 1, num);
		System.out.println("* ");

	}

	public static void box(int row, int col, int num) {
		// main base case
		if (row > num) {
			return;
		}

		// partial base case
		if (col > num) {
			System.out.println();
			box(row + 1, 0, num);
			return;
		}

		// calling part
		System.out.print("* ");
		box(row, col + 1, num);

	}

	public static void display(int[] arr, int vidx) {

		if (vidx == arr.length) {
			return;
		}

		System.out.print(arr[vidx]+ "  ");
		display(arr, vidx + 1);
	
	}

	public static String triangeSM(int num) {
		
		if(num<=0) {
			return "";
		}
		String p = triangeSM(num-1);
		p = p + "* ";
		System.out.println(p);
		return p;
	}

	public static String triange1SM(int num) {
		
		if(num<=0) {
			return "";
		}
		 
	String	p = triangeSM(num-1);
		p = p + "* ";
		System.out.println(p);
		return p;
	}

	public static void triangle(int row, int col, int num) {
		// main base case
		if (row > num) {
			return;
		}

		// partial base case
		if (col > row) {
			System.out.println();
			triangle(row + 1, 0, num);
			return;
		}

		// calling part
		System.out.print("* ");

		triangle(row, col + 1, num);
		
	}
	
	public static void triangleInvers(int row, int col, int num) {
		// main base case
		if (row > num) {
			return;
		}

		// partial base case
		if (col > num-row) {
			System.out.println();
			triangleInvers(row + 1, 0, num);
			return;
		}

		// calling part
		System.out.print("* ");

		triangleInvers(row, col + 1, num);
		
	
	}
	
	public static void vindex(int[] arr,int vidx) {
		//base case
		if(vidx==arr.length) {
			return;
		}
		//calling part
		System.out.println(arr[vidx]);
		vindex(arr, vidx+1);
	}
	
    public static int find(int[] arr, int vidx,int target) {
		//base case
		if(vidx == arr.length) {
			return -1;
		}
		//calling part
		if(arr[vidx]==target) {
			return vidx;
		}
		else {
			int ans = find(arr, vidx+1, target);
		    return ans;
		}
		
			
	}
	
    public static int findmax(int[] arr, int vidx) {
		//base case
		if(vidx==arr.length) {
			return arr[0];
		}
		//calling part
		
	   
	   int ans = findmax(arr, vidx+1);
	  if(arr[vidx]>ans) {
		  return arr[vidx];
		  
	  }else {
		  return ans;
	  }
		
			
		
	}
	
    public static void findallindx(int[] arr, int data,int vidx) {
		//base case
		if(vidx == arr.length) {
			//System.out.println("not found");
			return;
		}
		
		//calling part
		if(arr[vidx]==data) {
			System.out.println(vidx);
		}
		
			
		   // System.out.println(findallindx(arr,data, vidx+1));
		     findallindx(arr, data, vidx+1);
		    //return ans;
		    	
	
	}
	
    public static int[] findallindex(int[] arr, int data,int vidx,int fsofar) {
		//base case
		if(vidx == arr.length) {
			int ans[] = new int[fsofar];
			
		 return ans;
		}
		//calling part
		if(arr[vidx]==data) {
		    //fsofar++;
			int store[] = findallindex(arr,data,vidx+1, fsofar+1);
			store[fsofar] = vidx;
            return store;
		}
		else {
			int ans[] = findallindex(arr,data,vidx+1, fsofar);
		    return ans;  
		}
	
	}
	
    public static void bubblesort(int[] arr,int low,int hi) {
 		//base case
		if(hi == 0) {
		return ;	
		}
		
		//calling part
		if(low == hi) {
			low =0;
			bubblesort(arr,low, hi-1);
		    return;
			//hi = hi -1;
		}
		
		//swap
		if(arr[low]>arr[low+1]) {
		int temp =arr[low];
		arr[low]=arr[low+1];
		arr[low+1]=temp;
		}
		//calling
		
		bubblesort(arr, low+1, hi);
		
		
}
	
}
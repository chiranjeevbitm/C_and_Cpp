#include<iostream>
#include<math.h>


bool isPrime(int num) {

		int div = 2;
		bool flag = true;
		while (div <= num - 1) {
			if (num % div == 0) {
				flag = false;
				break;
			}
			div++;
		}
		if (flag) {
			return true; 
		} else {
			return false;
		}

	}
  void printAllPrimes(int ll, int ul) {
  		for (int counter = ll; counter <= ul; counter++) {
  			bool rv = isPrime(counter);
  			if (rv)
  				std::cout << counter << '\n';
  		}
  	}


int numberofDigits(int num) {
		int nod = 0;
		while (num != 0) {
			num = num / 10;
			nod++;
		}
		return nod;
	}

bool isArmstrong(int num, int nod) {
		int temp = num;
		int ans = 0;
		while (num != 0) {
			int rem = num % 10;
			ans = ans + (int) pow(rem, nod);
			num = num / 10;
		}
		if (ans == temp)
			return true;
		else
			return false;
	}

void printArmstrong(int ll, int ul) {
		for (int counter = ll; counter <= ul; counter++) {
			bool rv = isArmstrong(counter, numberofDigits(counter));
			if (rv)
       std::cout << counter << '\n';
		}
	}

int makeReverse(int num) {
		int rev = 0;
		int i = 1;
		int nod = numberofDigits(num);
		while (num != 0) {

			int rem = num % 10;
			// System.out.println(nod);

			rev += rem * (int) pow(10, (nod - i));
			// System.out.println(rev);
			num = num / 10;
			i++;
		}
		//std::cout << rev << '\n';
		return rev;
	}

void fibbonaci_no(int n) {

		int a =0;
		int b =1;
		int counter =0;
		while(counter<=n) {
		std::cout << a << ' ';
		int sum = (a+b);
		a = b;
		b = sum;
		counter++;

		}



	}
//
int rotation(int num, int k) {
		int result = 0;
		int nod = numberofDigits(num);
		// if k exceeds nod
		if (k > nod)
			k = k % nod;

		// if k is negative
		if (k < 0)
			k = k + nod;

	//	std::cout << nod << '\n';
		int part1 = num % ((int) pow(10, k));
	//	std::cout << part1 << '\n';
		int part2 = num / (int) pow(10, (k));
	//	std::cout <<part2<< '\n';
		result = part1 * (int) pow(10, (nod - k)) + part2;

		//std::cout << result << '\n';

		return result;

	}
//
// 	// This will give the integer part not the fractional
//
int log(int num, int base) {
		int counter = 0;
		while (num != 0) {
			num = num / base;
			counter++;
		}
    // std::cout << counter-1 << '\n';
		return counter - 1;
	}

int power(int num, int p) {
		int result = 1;
		while (p != 0) {
			result = result * num;
			p--;
		}
	//std::cout << result << '\n';
		return result;
	}

int  factorial(int num) {
		int result =  1;
		while(num!=0) {
			result = result*(num);
      num--;
		}
		//std::cout << result << '\n';
		return result;
	}







// make functions for 1 prime
//2 Armstrong and its parts
//3 log
//4 power
int main(){



		//std::cout << "Enter a number" << '\n';
		//int num;
    //std::cin >> num;
    //std::cout << "factorial of " << num << " is " << factorial(num)<<'\n';
    //std::cout << power(3,2)<<'\n';
    //std::cout << log(100,10) << '\n';
      //std::cout << rotation(1234,2) << '\n';
      //fibbonaci_no(5) ;
     //printArmstrong(10,1800);
     printAllPrimes(1,100);




}

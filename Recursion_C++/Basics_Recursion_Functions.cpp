#include <iostream>

void PrintDecreasing(int num) {
  if (num == 0)
    return;

  std::cout << num << ' ';

  PrintDecreasing(num - 1);
}

void PrintIncreasing(int num) {
  if (num == 0)
    return;
  PrintIncreasing(num - 1);
  std::cout << num << ' ';
}

void PrintDI(int num) {
  if (num == 0)
    return;
  PrintDI(num - 1);
  std::cout << num << ' ';
  PrintDI(num - 1);
}

void PrintDISkip(int num) {
  if (num == 0)
    return;
  if (num % 2 == 1)
    std::cout << num << '\n';
  PrintDISkip(num - 1);
  if (num % 2 == 0)
    std::cout << num << '\n';
}

int Factorial(int num) {
  if (num == 0 || num == 1)
    return 1;

  int fact = Factorial(num - 1);
  int result = num * fact;

  return result;
}

int Power(int base, int p) {
  if (base == 0)
    return 0;
  if (base == 1 || p == 0)
    return 1;

  int res = Power(base, p - 1);
  int result = base * res;

  return result;
}

int PowerBtr(int base, int p) {
  if (base == 0)
    return 0;
  if (base == 1 || p == 0)
    return 1;

  int res = PowerBtr(base, p / 2);
  int result = res * res;

  if (p % 2 == 1)
    result = result * base;

  return result;
}

int Fibonnaci(int num) {
  if (num == 0)
    return 0;
  if (num == 1)
    return 1;

  int fib1 = Fibonnaci(num - 1);
  int fib2 = Fibonnaci(num - 2);

  int res = fib1 + fib2;
  return res;
}

void fibseries(int num) {
  for (int i = 1; i <= num; i++)
    std::cout << Fibonnaci(i) << ' ';
}

void PrintColumns(int col, int num) {
  if (col > num)
    return;

  std::cout << "*" << ' ';
  PrintColumns(col + 1, num);
}

void PrintRows(int row, int num) {
  if (row > num)
    return;

  std::cout << "*" << '\n';
  PrintRows(row + 1, num);
}

void PrintBox(int row, int col, int n) {
  if (row > n)
    return;
  if (col > n) {
  }
}
int main() {
  // int num;
  // PrintDecreasing(10);
  // PrintIncreasing(10);
  // PrintDI(10);
  // PrintDISkip(10);
  // std::cout << "Factorial of given number =" << Factorial(5) << '\n';
  // std::cout << "Power of the number = " << Power(2, 10) << '\n';
  // std::cout << "Power of the number = " << PowerBtr(2, 10) << '\n';
  // std::cout << Fibonnaci(6) << '\n';
  // fibseries(10);
  // PrintColumns(1, 5);
  // PrintRows(1, 5);
}
//     PrintRows PrintColumns
//  PrintTriangle display displayReverse bubbleSort

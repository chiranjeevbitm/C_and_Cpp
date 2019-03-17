#include <stdio.h>
int main() {
  // int c = 10;
  // int b;
  // printf("%d\n", ++c + ++c);
  int a = 1;
  int b = 3;
  // int A = a++ - --b + ++a;
  // int A = ++b + --a - a++;
  int A = a++ + b;
  printf("%d\n", A);
  return 0;
}

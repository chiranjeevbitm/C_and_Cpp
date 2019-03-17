#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000


void fun2(int n) {
  if (n <= 0)
    return;
  if (n > LIMIT)
    return;
  printf("above function call  %d \n", n);
  fun2(2 * n);
  printf("below function call  %d \n", n);
}
int main() {
  fun2(5);
  return 0;
}

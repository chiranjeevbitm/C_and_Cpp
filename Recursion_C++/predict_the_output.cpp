#include <stdio.h>
int fun(int a[], int n) {
  int x;
  if (n == 1)
    return a[0];
  else
    x = fun(a, n - 1);
  if (x > a[n - 1])
    return x;
  else
    return a[n - 1];
}

int fun2(int i) {
  if (i % 2)
    return (i++);
  else
    return fun2(fun2(i - 1));
}

int fun3(int n) {
  if (n > 100)
    return n - 10;
  return fun3(fun3(n + 11));
}

void abc(char *s) {
  if (s[0] == '\0')
    return;

  abc(s + 1);
  abc(s + 1);
  printf("%c", s[0]);
}

#include <stdio.h>
int fun4(int count) {
  printf("%d\n", count);
  if (count < 3) {
    fun4(fun4(fun4(++count)));
  }
  return count;
}
int main() {
  int arr[] = {120, 10, 30, 50, 100};
  printf(" %d ", fun(arr, 5));
  abc("xyz");
  getchar();
  return 0;
}

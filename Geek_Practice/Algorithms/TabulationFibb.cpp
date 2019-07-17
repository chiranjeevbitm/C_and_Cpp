#include<iostream>

int fib(int n)
{
  int fibo[n+1];
  int i;
  fibo[0] = 0;
  fibo[1] = 1;
  for(i=2;i<=n;i++)
  {
    fibo[i] = fibo[i-1]+fibo[i-2];
  }
  return fibo[n];
}

int main()
{
  int n;
  std::cin >> n;
  std::cout << "fibonacci is  " <<fib(n)<< '\n';
  return 0;
}

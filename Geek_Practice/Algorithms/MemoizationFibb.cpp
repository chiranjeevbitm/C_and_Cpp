#include<iostream>
using namespace std;
#define NIL -1
#define MAX 100

int lookup[MAX];

void init()
{
  int i;
  for(i=0;i<MAX;i++)
    lookup[i] = NIL;
}

int fib(int n)
{
  if(lookup[n]==NIL)
  {
    if(n<=1)
    lookup[n]=n;
    else
    lookup[n] = fib(n-1) +fib(n-2);
  }
  return lookup[n];
}

int main()
{
  int n;
  cin>>n;
  init();
  cout<<"fibonacci is "<<fib(n)<<'\n';
  return 0;
}

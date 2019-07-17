#include<iostream>
using namespace std;
int power(int a,int b)
{
  if(b==0)
  return 1;

  int smallAns = power(a,b/2);
  smallAns *=smallAns;

  if(b%2==1)
  smallAns = a*smallAns;

  return smallAns;
}
int main()
{
  int a,b;
  cin>>a>>b;
  cout<<power(a,b)<<'\n';
}

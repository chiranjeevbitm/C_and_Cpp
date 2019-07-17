#include<iostream>
#include<cstring>
#define ll long long
using namespace std;


int main()
{
  char a[20];
  cin>>a;
  int len = strlen(a);
  ll ans =0;
  ans = (1<<len) -2;     //ie (2^len - 2)
  for(int i=len-1,pos=0;i>=0;i--,pos++)
  {
    if(a[i]=='7')
    {
      ans+=(1<<pos);
    }
  }
  cout<<ans+1<<"\n";
}

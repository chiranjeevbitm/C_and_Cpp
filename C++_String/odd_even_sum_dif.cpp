#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  string s;
  cin>>s;
  int n = s.length();
  int sume=0;
  int sumo=0;
  int sum=0;
  for(int i=0;i<n;i=i+2)
  {
    sumo=sumo+(int(s[i])-48);
  }
  for(int i=1;i<n;i=i+2)
  {
    sume=sume+(int(s[i])-48);
  }
  if(sume>sumo)
  {
    cout<<(sume-sumo)<<"\n";
  }
  else
  {
    cout<<(sumo-sume)<<"\n";
  }
}
}

#include<iostream>
using namespace std;

long int GCD(long int v1,long int v2)
{
  while(v2>0)
  {
      int temp=v2;
      v2=v1%v2;
      v1=temp;
  }
  return v1;
}

long int LCM(long int v1,long int v2)
{
  long int x=gcd(v1,v2);
  return (v1*v2/x);
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    long int a,b;
	    cin>>a>>b;
	    cout<<LCM(a,b) << ' ' << GCD(a,b)<<'\n';
	}
	return 0;
}

#include<iostream>
#include<math.h>
using namespace std;
int min(double x,double y)
{
    return (x<y)?x:y;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	double h,m;

	cin>>h>>m;
  if(m==60) m=0;
  if(h==12) h=0;
  double a=fabs((60*h)-(11*m))/2.0;
  cout<<min(360-a,a)<<'\n';
	}

	return 0;
}

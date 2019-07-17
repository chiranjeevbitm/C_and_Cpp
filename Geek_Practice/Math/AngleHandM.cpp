#include<iostream>
#include<math.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	float h,m;
	float h_a,m_a;
	cin>>h>>m;
  if(m==60)
  	 h_a = (h)*30;
  else
	 h_a = (h + m/60)*30;

	 m_a = m * 6 ;
	int res = fabs(h_a-m_a);
  cout<<floor(res)<<'\n';
	}

	return 0;
}

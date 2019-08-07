#include<iostream>
using namespace std;
#include<cmath>
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int res = floor(n/5) + floor(n/25) +floor(n/125) + floor(n/625);
	cout<<res<<'\n';
	}
	return 0;
}

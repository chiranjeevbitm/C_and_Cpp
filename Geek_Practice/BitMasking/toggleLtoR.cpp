#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n,l,r;
	cin>>n>>l>>r;
	for(int i=l;i<=r;i++)
	{
	    n = (1<<(i-1)^n);
	}
	cout<<n<<'\n';

	}
	return 0;
}

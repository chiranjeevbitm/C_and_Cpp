
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n,k;
	cin>>n,k;
	int res;
	while(k>-1)
	{
	    res= n%2;
	    n=n/2;
	    k--;
	}
	if(res==1)
	cout<<"Yes"<<'\n';
	else
	cout<<"No"<<'\n';

	}
	return 0;
}

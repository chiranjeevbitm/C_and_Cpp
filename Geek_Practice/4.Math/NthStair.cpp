#include<iostream>
using namespace std;

int Nstair(int n)
{

    if(n==1||n==0)
    return 1;
    // if(n==0)
    // return 0;

    return (1+Nstair(n-2));
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	cout<<Nstair(n)<<'\n';

	}
	return 0;
}

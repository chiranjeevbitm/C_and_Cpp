#include<iostream>
#include<math.h>
using namespace std;
long long int m=pow(10,9)+7;


int main()
 {
	int t;
	cin>>t;
	long long int dp[100000];
    dp[0] =1;
    dp[1] = 1;
    for(int i=2;i<=100000;i++)
    {
        dp[i] = ((dp[i-1])%m+(dp[i-2])%m)%m;
    }
    while(t--)
	{
	int n;
	cin>>n;
    cout<<dp[n]<<'\n';
	}
	return 0;
}

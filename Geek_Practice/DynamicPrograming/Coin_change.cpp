#include<iostream>
using namespace std;
#include<cstring>
#define ll long long
ll memo[301][301];

ll coin_change_memo(ll coins[],ll amount,ll n)
{
    if(amount==0)   return 1;
    if(amount<0||n<=0) return 0;

    if(memo[n][amount]!=-1)
        return memo[n][amount];

    ll ans = coin_change_memo(coins,amount-coins[n-1],n) + coin_change_memo(coins,amount,n-1);
    memo[n][amount]=ans;

    return memo[n][amount];
}
int main()
 {
	ll t;
	cin>>t;
	while(t--)
	{
	ll n,amount;
	cin>>n;
	ll coins[n];
	for(ll i=0;i<n;i++) cin>>coins[i];
	cin>>amount;

	memset(memo,-1,sizeof(memo));

	cout<<coin_change_memo(coins,amount,n)<<'\n';
	}
	return 0;
}

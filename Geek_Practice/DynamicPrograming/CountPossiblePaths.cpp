#include<iostream>
using namespace std;
#include<math.h>
long long int mod=pow(10,9)+7;
#define ll long long
#include<cstring>

ll memo[101][101];

ll waysRec(int n,int m)
{
  if(n==0 || m==0) return 0;
  if(n==1||m==1)  return 1;

  return waysRec(n-1,m)+waysRec(n,m-1);

}
ll waysmemo(int n,int m)
{
  if(n==0 || m==0) return 0;
  if(n==1||m==1)  return 1;

  if(memo[n][m]!=-1)  return memo[n][m];

  ll ans = (waysmemo(n-1,m)%mod+waysmemo(n,m-1)%mod)%mod;
  memo[n][m] = ans;
  return ans;

}

ll waysdp(int n,int m)
{
  int dp[n][m];
  for(ll i=0;i<n;i++)
  {
    for(ll j=0;j<m;j++)
    {
      if(i==0||j==0)
        dp[i][j] = 1;
      else
        dp[i][j] = ((dp[i-1][j])%mod + (dp[i][j-1])%mod)%mod;

  }
  return dp[n-1][m-1];
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n,m;
	cin>>n>>m;
  //cout<<waysRec(n,m)<<'\n';

  memset(memo,-1,sizeof(memo));
	cout<<waysmemo(n,m)<<'\n';
	}
	return 0;
}

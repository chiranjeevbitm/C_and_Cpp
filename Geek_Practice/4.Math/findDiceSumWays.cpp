#include<iostream>
#include<string.h>
#define ll long long
ll dp[55][55];
using namespace std;



ll findWays(ll m, ll n, ll x)
{
 if(x==0 && n==0)
 return 1;
 if(x<0 || n==0)
 return 0;
 if(dp[n][x]!=-1)
 return dp[n][x];


 ll res=0;

 for(ll i=1;i<=m;i++)
 res+=findWays(m,n-1,x-i);

 return dp[n][x]=res;
}



// DP

long findWaysDP(int f, int d, int s)
{
  // Create a table to store results of subproblems. One extra
  // row and column are used for simpilicity (Number of dice
  // is directly used as row index and sum is directly used
  // as column index). The entries in 0th row and 0th column
  // are never used.
  long mem[d + 1][s + 1];
  memset(mem,0,sizeof mem);
  // Table entries for no dices
  // If you do not have any data, then the value must be 0, so the result is 1
  mem[0][0] = 1;
  // Iterate over dices
  for (int i = 1; i <= d; i++)
  {
      // Iterate over sum
      for (int j = i; j <= s; j++)
      {
          // The result is obtained in two ways, pin the current dice and spending 1 of the value,
          // so we have mem[i-1][j-1] remaining combinations, to find the remaining combinations we
          // would have to pin the values ??above 1 then we use mem[i][j-1] to sum all combinations
          // that pin the remaining j-1's. But there is a way, when "j-f-1> = 0" we would be adding
          // extra combinations, so we remove the combinations that only pin the extrapolated dice face and
          // subtract the extrapolated combinations.
          mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1];
          if (j - f - 1 >= 0)
              mem[i][j] -= mem[i - 1][j - f - 1];
      }
  }
  return mem[d][s];
}

int main()
 {
	ll t;
	cin>>t;
	while(t--)
	{
	ll m,n,x;
	cin>>m>>n>>x;
	memset(dp,-1,sizeof dp);
	cout<<findWaysDP(m,n,x)<<'\n';
	}
	return 0;
}

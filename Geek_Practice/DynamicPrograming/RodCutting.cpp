#include<iostream>
using namespace std;
int memo[1000];

int max_profit(int arr[],int n)
{
  if(n==0)    return 0;

  int best = 0;
  for(int len=1;len<=n;len++)
  {
    int netprofit = arr[len] + max_profit(arr,n-len);
    best= max(best,netprofit);
  }
  return best;
}

int max_profit_memo(int arr[],int n)
{
  if(n==0)    return 0;

  if(memo[n]!=-1)
  {
    return memo[n];
  }

  int best = 0;
  for(int len=1;len<=n;len++)
  {
    int netprofit = arr[len] + max_profit(arr,n-len);
    best= max(best,netprofit);
    memo[len] = best;
  }
  return memo[n];
}
int max_profit_dp(int arr[],int n)    // bottom Up
{
  int dp[1000] = {};
  for(int len=1;len<=n;len++)
  {
    int best=0;
    for(int cut=1;cut<=len;cut++)
    {
     best = max(best,arr[cut]+dp[len-cut]);
    }
  dp[len] = best;
}
  return dp[n];
}

int main()
{
  int priceOfEachLen[100];
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)   cin>>priceOfEachLen[i];

  // int ans = max_profit(priceOfEachLen,n);
  // cout<<ans<<'\n';

  // memset(memo,-1,sizeof(memo));
  // int ans = max_profit_memo(priceOfEachLen,n);
  // cout<<ans<<'\n';

  int ans = max_profit_dp(priceOfEachLen,n);
  cout<<ans<<'\n';

  return 0 ;
}

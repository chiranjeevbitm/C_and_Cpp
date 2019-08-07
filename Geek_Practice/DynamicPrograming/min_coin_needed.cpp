#include<iostream>
#include<cstring>
#include<limits.h>
using namespace std;
int memo[1000];

int coin_needed_rec(int coins[],int amount,int n)
{
  //base case
  if(amount==0)
  {
    return 0;
  }
  //recursive
  int ans = INT_MAX;
  for(int i=0;i<n;i++)
  {
    if(amount-coins[i]>=0)
    {
      int smalans = coin_needed_rec(coins,amount-coins[i],n);
      if(smalans!=INT_MAX)
      {
        ans = min(ans,smalans+1);
      }
    }
  }
  return ans;

}
// int coin_needed_memo(int coins[],int amount,int n)
// {
//   //base case
//   if(amount==0)
//   {
//     return 0;
//   }
//   if(memo[n]!=-1)
//   {
//     return memo[n];
//   }
//   //recursive
//   int best = INT_MAX;
//   for(int i=0;i<n;i++)
//   {
//     if(amount-coins[i]>=0)
//     {
//       int smalans = coin_needed_memo(coins,amount-coins[i],n);
//       if(smalans!=INT_MAX)
//       {
//         best = min(best,smalans+1);
//         memo[i] = best;
//       }
//     }
//   }
//   return memo[n-1];
//
// }

// int coin_needed_dp(int coins[],int amount,int n)
// {
//   int dp[amount];
//   // for(int i=0;i<n;i++)
//   // {
//   //   dp[i] = INT_MIN;
//   // }
//
//   //base case
//   dp[0]=1;
//   //recursive
//
//   for(int i=1;i<=amount;i++)
//   {
//     dp[i]=INT_MAX;
//     for(int j=0;j<n;j++)
//     {
//       if(coins[i]<=amount)
//       {
//       int smallerans = dp[i-coins[j]];
//       if(smallerans!=INT_MAX)
//       {
//         dp[i] = min(dp[i],smallerans+1);
//       }
//     }
//   }
//   }
//   return dp[n];
//
// }
//


int main()
{
  int  coins[] ={1,7,10};
  int n=3;
  int amount =15;
  //cout<<coin_needed_rec(coins,15,3)<<'\n';
  //
  memset(memo,-1,sizeof(memo));
  cout<<coin_needed_memo(coins,15,3)<<'\n';


  //cout<<coin_needed_dp(coins,15,3)<<'\n';

  return 0;
}

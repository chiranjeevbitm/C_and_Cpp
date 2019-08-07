#include<iostream>
using namespace std;
#include<cstring>
#include<limits.h>
int memo[10000];

int reduce_no(int n)
{
  if(n==1)
  {
    return 0;
  }
  int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;

  if(n%3==0) q1 = 1+reduce_no(n/3);
  if(n%2==0) q2 = 1+reduce_no(n/2);
  q3 = 1+reduce_no(n-1);

  return min(q1,min(q2,q3));

}
int reduce_noTopDown(int n)
{

  if(n==1)
  {
    return 0;
  }
  int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
  if(memo[n]!=-1)
  {
    return memo[n];
  }

  if(n%3==0) q1 = 1+reduce_no(n/3);
  if(n%2==0) q2 = 1+reduce_no(n/2);
  q3 = 1+reduce_no(n-1);

  memo[n] = min(q1,min(q2,q3));

  return memo[n];

}
int reduce_noDP(int n)
{
  int dp[10000];
  //Base case
  dp[0]=0;  dp[2]=1;
  dp[1]=0;  dp[3]=1;


  for(int i=4;i<=n;i++)
  {
  int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;

  if(i%3==0) q1 = 1+dp[i/3];

  if(i%2==0) q2 = 1+dp[i/2];

  q3 = 1+dp[i-1];

  dp[i] = min(q1,min(q2,q3));
  }
  return dp[n];

}

int main()
{
  int n;
  cin>>n;

  //cout<<reduce_no(n)<<'\n';

  // memset(memo,-1,sizeof(memo));
  // cout<<reduce_noTopDown(n)<<'\n';

  cout<<reduce_noDP(n)<<'\n';

  return 0;
}

#include<iostream>
using namespace std;
#include<cstring>
#include<limits.h>
//int ncall =0;
int calls = 0;
int memo[100][100];

int max_profit(int arr[],int s,int e,int y)
{
//  ++ncall;
  if(s>e) return 0;

  int q1 = arr[s] * y + max_profit(arr,s+1,e,y+1);
  int q2 = arr[e] * y + max_profit(arr,s,e-1,y+1);

  return (max(q1,q2));
}
int max_profitMEMO(int arr[],int s,int e,int y)
{
  ++calls;
  if(s>e) return 0;
  if(memo[s][e]!=-1)
  {
    return memo[s][e];
  }
  int q1 = arr[s] * y + max_profit(arr,s+1,e,y+1);
  int q2 = arr[e] * y + max_profit(arr,s,e-1,y+1);

  int ans =  max(q1,q2);
  memo[s][e] = ans;
  return ans;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)  cin>>arr[i];
  //
  // cout<<max_profit(arr,0,n-1,1)<<'\n';
  // cout<<ncall<<'\n';

  memset(memo,-1,sizeof(memo));
  cout<<max_profitMEMO(arr,0,n-1,1)<<'\n';
  cout<<calls<<'\n';
  return 0;
}

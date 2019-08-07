#include<iostream>
using namespace std;
#include<limits.h>

int maxSum(int a[],int n)
{
    int dp[n];
   for(int i=0;i<n;i++)
   {
       dp[i] = a[i];
   }
    for(int i=0;i<n;i++)
   {
       for(int j=0;j<i;j++)
       {
           if(a[i]>a[j])
           {
               dp[i]=max(dp[i],dp[j]+a[i]);
           }
       }
   }
   int m = INT_MIN;
   for(int i=0;i<n;i++)
  {

   if(dp[i]>m)
   m = dp[i];
   }
    return m;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)    cin>>arr[i];
	cout<<maxSum(arr,n)<<'\n';

	}
	return 0;
}

#include<iostream>
using namespace std;

int NstairDP(int n,int k)
{
   int dp[n];
   dp[0]=1;
   for(int step=1;step<=n;step++)
   {
   dp[step]=0;
   for(int j=1;j<=k;j++)
   {
     if(step-j>=0)
       dp[step]=dp[step]+dp[step-j];
   }
   }
   return dp[n];
}
// int NstairWindow(int n,int k)
// {
//    int dp[n+1];
//    dp[0]=1;
//    for(int step=1;step<=n;step++)
//    {
//
//        dp[step+1]=2*dp[step]-dp[step-k];
//
//    }
//    return dp[n];
// }
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n,k;
  std::cout << "Enter total stair length and max size of step" << '\n';
	cin>>n>>k;
	//cout<<NstairDP(n,k)<<'\n';
  cout<<NstairWindow(n,k)<<'\n';
	}
	return 0;
}

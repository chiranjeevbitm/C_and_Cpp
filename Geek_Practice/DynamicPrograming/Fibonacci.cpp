#include<iostream>
using namespace std;
#include<cstring>
#define ll long long
int mem[100];
void fibBottumUp(ll n)
{
  ll memo[n];
  memo[0]=0;
  memo[1]=1;
  for(ll i=2;i<=n;i++)
  {
  memo[i]=memo[i-1]+memo[i-2];
  }
  for(ll i=1;i<=n;i++)
  {
  cout<<memo[i]<<" ";
  }
    cout<<'\n';
  }
int fibTopDown(int n)
{

  if(n==0) return 0;
  if(n==1) return 1;

  if(mem[n]!=-1)
  {
    return mem[n];
  }
  int res = fibTopDown(n-1) +fibTopDown(n-2);
  mem[n] = res;
  return res;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
  //fibBottumUp(n);


  for(int i=1;i<=n;i++) mem[i]=-1;
  for(int i=1;i<=n;i++) cout<<fibTopDown(i)<<" ";
  std::cout << '\n';
}
	return 0;
}

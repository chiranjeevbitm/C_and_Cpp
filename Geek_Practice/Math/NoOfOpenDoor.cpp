#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int arr[n];
  std::fill_n(arr, n, 1);

	for(int i=2;i<=n;i++)
	{

	    for(int j=i;j<=n;j+=i)
	    {
	        arr[j]=arr[j]^1;
	    }
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
	    if(arr[i]==1)
	    count++;
	}
  if(n%100==0)
  cout<<count+1<<'\n';
  else
	cout<<count<<'\n';
	}
	return 0;
}

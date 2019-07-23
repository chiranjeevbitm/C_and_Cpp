#include<iostream>
using namespace std;
#include<algorithm>

int main()
{

  int t;
  std::cin >>t ;
  while(t--)
  {
    int  n;
    cin>>n;
    int arr[n];
  for(int i=0;i<n;i++)  cin>>arr[i];
  sort(arr,arr+n,greater<int>());

  int res[n];
  int l=0;
  int r=n-1;

  for(int i=0;i<n;i++)
  {
   if(i%2==0)
   res[r--]=arr[i];
   else
   res[l++]=arr[i];

    }
    if(n%2==0)
    {
    for(int i=0;i<n;i++)  cout<<res[i]<<' ';
    std::cout  << '\n';
    }
    else
    {
      for(int i=n-1;i>=0;i--)  cout<<res[i]<<' ';
      std::cout  << '\n';
    }
}

return 0;
}

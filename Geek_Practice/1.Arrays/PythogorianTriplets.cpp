#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

bool isTriplets(int arr[],int n)
{
  for(int i = 0;i<n;i++)
  arr[i] = arr[i]*arr[i];

  sort(arr,arr+n);

  for(int i=n-1;i>=2;i--)
  {
    int l = 0;
    int r = i-1;
    while(l<r)
    {
      if(arr[l]+arr[r]==arr[i])
      return true;

       (arr[l]+arr[r]<arr[i])? l++ : r--;
     }
  }

  return false;
}



int main()
{
  long int n;
  int t;
  std::cin >>t ;
  while(t--)
  {
  std::cin >> n;
  int arr[n];
  for(int i=0;i<n;i++)
  std::cin >> arr[i];
  isTriplets(arr,n) ? std::cout << "Yes" :std::cout << "No";
  std::cout << '\n';
}
return 0;
}

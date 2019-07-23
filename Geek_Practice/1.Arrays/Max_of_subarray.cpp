#include<iostream>
#include<climits> 

using namespace std;

void submax(int arr[],int k,int n)
{
  int max = INT_MIN;
  for(int i=0;i<n-k+1;i++)
  {
    max = arr[i];
    for(int j=i;j<(i+k);j++)
    {
    max = max>arr[j]?max:arr[j];
    }
    std::cout << max << ' ';
    max = INT_MIN;
  }
}

int main()
{
  long int n,k;
  int t;
  std::cin >>t ;
  while(t--)
  {
  std::cin >> n;
  std::cin >> k;

  int arr[n];
  for(int i=0;i<n;i++)
  std::cin >> arr[i];
  //
   submax(arr,k,n);
   std::cout  << '\n';

}
return 0;
}

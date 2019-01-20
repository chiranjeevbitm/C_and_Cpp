#include<iostream>
using namespace std;

void subArraySum(int arr[], int n, int sum)
{
 int sum1;
  for(int i =0;i<n;i++)
  {
    sum1 = arr[i];
  for(int j =i+1;j<=n;j++)
  {

    if(sum1 == sum)
    {
      std::cout << i+1 <<" " << j<< '\n';
      return;
    }
    if(sum1>sum|| j==n)
    break;

  sum1 +=arr[j];
}
 }
 std::cout << -1 << '\n';

}

int main()
{
  int t,n,sum;

  std::cin >>t ;
  while(t--)
  {
  std::cin >> n;
  std::cin >> sum;
  int arr[n];
  for(int i=0;i<n;i++)
  std::cin >> arr[i];

  subArraySum(arr,n,sum);
}
return 0;
}

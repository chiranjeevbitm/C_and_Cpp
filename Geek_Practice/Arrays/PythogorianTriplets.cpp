#include<iostream>
#include<cmath>

using namespace std;

bool triplets(int arr[],int n)
{
  sort(arr,arr+n);

  for(int i=0;i<n-2;i++)
  {
    double a = sqrt(arr[i]);
    double b = sqrt(arr[i+1]);
    double c = sqrt(arr[i+2]);
    if(a + b == c)
    return true;
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
   if(triplet(arr,n))
   std::cout << "Yes" << '\n';
   else
   std::cout << "No" << '\n';


}
return 0;
}

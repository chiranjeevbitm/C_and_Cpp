#include<iostream>
using namespace std;

int findMaxSum(int arr[],int n)
{
  int incl = arr[0];
  int excl = 0;
  int excl_new;
  for(int i=0;i<n;i++)
  {
    excl_new = (incl>excl)? incl:excl;
    incl = excl+arr[i];
    excl = excl_new;
  }
  return ( (incl>excl)? incl:excl);
}
int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout<< findMaxSum(arr, n)<<'\n';
  return 0;
}

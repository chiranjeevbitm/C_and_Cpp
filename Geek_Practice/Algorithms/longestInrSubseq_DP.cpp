#include<iostream>

using namespace std;

int LIS(int a[],int n)
{
  int list[n];
  list[0] =1;
  for(int i=1;i<n;i++)
  {
    list[i] =1;
    for(int j=0;j<i;j++)
    {
      if(a[i]>a[j] && list[i]<list[j]+1)
      list[i] =list[j]+1;
    }

  }
  return *max_element(list,list+n);
}
int main()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Length of list is  "<< LIS( arr, n ) << '\n';
  return 0;
}

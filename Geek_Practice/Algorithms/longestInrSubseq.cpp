#include<iostream>
using namespace std;

int list(int a[],int n,int *max)
{
  //base case
  if(n==1)
    return 1;

    int res , max_end =1;
    for(int i=0;i<n;i++)
    {
      res = list(a,i,max);
      if(a[i-1]<a[n-1] && res+1 >max_end)
          max_end = res+1;
    }
    if(*max <max_end)
      *max = max_end;

    return max_end;
}

int wraperforList(int a[],int n)
{
  int m =1;
  list(a,n,&m);
  return m;
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of lis is "<<awraperforList( arr, n )<< '\n';
    return 0;
}

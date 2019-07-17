#include<iostream>
#include<vector>
using namespace std;
void mergeSortedAry(int a1[],int a2[],int l1,int l2,int a[])
{
  int i =0,j=0,k=0;
  while(i<l1 && j<l2)
  {
    if(a1[i]<a2[j])
        a[k++]=a1[i++];
    else
        a[k++] = a2[j++];
  }
  while(i<l1)
    a[k++]=a2[i++];
  while(j<l2)
    a[k++]=a2[j++];
}
int main()
{
 int n;
 cin>>n;
 int a1[n];
 int a2[n];
 for(int i=0;i<n;i++)  cin>>a1[i];

 for(int i=0;i<n;i++)  cin>>a2[i];
 int res[n+n];
 mergeSortedAry(a1,a2,n,n,res);


 //for(int i=0;i<n+n;i++)  cout<<res[i]<<" ";
}

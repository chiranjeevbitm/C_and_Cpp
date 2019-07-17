#include<iostream>
#include<vector>
using namespace std;
int median(int a1[],int a2[],int n)
{
  int i=0,j=0;
  int m1= -1;
  int m2 = -1;
  int count;
  for(count=0;count<=n;count++)
  {
    if(i==n)
    {
      m1=m2;
      m2=a2[0];
      break;
    }
    if(j==n)
    {
      m1=m2;
      m2=a1[0];
      break;
    }
    if(a1[i]<a2[j])
    {
      m1=m2;
      m2=a1[i];
      i++;
    }
  else
    {
      m1=m2;
      m2=a2[j];
      j++;
    }
  }
  return (m1+m2)/2;
}
int main()
{
 int n;
 cin>>n;
 int a1[n];
 int a2[n];
 for(int i=0;i<n;i++)  cin>>a1[i];

 for(int i=0;i<n;i++)  cin>>a2[i];

 std::cout << median(a1,a2,n) << '\n';


 //for(int i=0;i<n+n;i++)  cout<<res[i]<<" ";
}

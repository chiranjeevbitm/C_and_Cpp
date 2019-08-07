#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

// int contains(int a[],int n)
// {
//
// }

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    vector<int>v;
    int num,flag=0;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
       num = a[i];
      while(num>0)
      {
        int x = num%10;
        if(x==1||x==2||x==3)
        {
          flag=1;
        }
        else
        {
          flag=0;
          break;
        }
       num=num/10;
      }
       if(flag==1)
       v.push_back(a[i]);
    }
    if(flag==0 && v.size()==0)
    {
    cout<<-1;
  }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";

    cout<<'\n';
  }
return 0;
}

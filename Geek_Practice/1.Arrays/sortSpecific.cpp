#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#define ll long long

int main()
{

  int t;
  std::cin >>t ;
  while(t--)
  {
    ll n,a;
    cin>>n;
    vector<ll> v1,v2;
    while(n--)
    {
      cin>>a;
      if(a%2==0)
        v1.push_back(a);
      else
        v2.push_back(a);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=v2.size()-1;i>=0;i--) cout<<v2[i]<<' ';
    for(int i=0;i<v1.size();i++) cout<<v1[i]<<' ';
    std::cout<< '\n';

  }
return 0;
}

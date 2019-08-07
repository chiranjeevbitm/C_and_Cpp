#include<iostream>
#include<string.h>
#include <algorithm>
using namespace std;
#include<limits.h>
#include <map>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    int n;
    cin>>n;
    string a[n];
    string ans="";
		int flag =0;
    int max = INT_MIN;
		map<string,int>hash;;
    for(int i=0;i<n;i++)
		{
        cin>>a[i];
				hash[a[i]]++;
			}
    for(auto x:hash)
    {
 	    if(max<x.second)
			{
        ans = x.first;
        max = x.second;
    }
    else if(max == x.second)
    {
      if(x.first.compare(ans)>0)
      ans = x.first;
    }
    }
    cout<<ans<<'\n';

    }
	return 0;
}

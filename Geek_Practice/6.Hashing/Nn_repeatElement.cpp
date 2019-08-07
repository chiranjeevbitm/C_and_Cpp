#include<iostream>
#include<string.h>
#define ll long long
using namespace std;

#include <unordered_map>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    ll n;
    cin>>n;
    ll a[n];
		int flag =0;
		unordered_map<ll,int>hash;;
    for(int i=0;i<n;i++)
		{
        cin>>a[i];
				hash[a[i]]++;
			}
    for(int i=0;i<n;i++)
    {
 	    if(hash[a[i]]==1)
			{
			flag =1;
			cout<<a[i]<<'\n';
			break;
		}
    }

    if(flag==0)
 	  cout<<0<<'\n';



}

	return 0;
}

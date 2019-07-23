#include<iostream>
using namespace std;
#define ll long long
#include<string.h>
int main()
 {
	ll t;
	cin>>t;
	while(t--)
	{
	string s,s1;
	ll k,n,count=0;
	char ch;
	cin>>s;
	s1=s;
	cin>>k>>n;
	cin>>ch;
	for(ll i=0;i<k;i++)
	{
	    s +=s1;
	}
	for(ll i=0;i<n;i++)
	{
	    if(s[i]==ch)
	    count++;
	}
	cout<<count<<'\n';


	}
	return 0;
}

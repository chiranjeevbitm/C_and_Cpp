#include<iostream>
using namespace std;
string rotate(string s,int n,int k)
{
    string ans = "";
    for(int i=n-k;i<n;i++)
    {
        ans+=s[i];
    }
    for(int i=0;i<n-k;i++)
    {
        ans+=s[i];
    }
    return ans;
}

char extract(string s,int pos)
{
    char ans;
    for(int i=0;i<s.length();i++)
    {
      if(i==pos)
      ans = s[i];
    }
    return ans;
}


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
  string ans;
	while(k--)
	{
	 int typ,p;
	 cin>>typ>>p;

        if(typ==1)
    	{
    	     ans = rotate(s,n,p);
           s=ans;

    	}

    	if(typ==2)
    	{
    	        cout<<extract(ans,p)<<'\n';
    	}
    }
	}
	return 0;
}

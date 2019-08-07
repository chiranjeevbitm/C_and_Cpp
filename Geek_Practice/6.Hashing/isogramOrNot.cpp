#include<iostream>
#include<string.h>
using namespace std;
#include<limits.h>
#include <unordered_map>

int is_isogram(string s,int n)
{
  unordered_map<char,int>hash;
  for(int i=0;i<s.length();i++)
  {
 	  hash[s[i]]++;
  }
  for(auto x:hash)
  {
      if(x.second>1)
        return 0;
  }
 	return 1;

}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
    string s;
    cin>>s;
    int n = s.length();
    if(is_isogram(s,n))
    cout<<1<<'\n';
    else
    cout<<0<<'\n';
	}
	return 0;
}

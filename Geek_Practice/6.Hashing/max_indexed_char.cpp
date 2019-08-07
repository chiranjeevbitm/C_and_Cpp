#include<iostream>
#include<string.h>
using namespace std;
#include<limits.h>
#include <unordered_map>

char get(string str,string patt)
{
    unordered_map<char,int>hash;
    for(int i=0;i<patt.length();i++)
    {
         hash[patt[i]]++;
    }
     for(int i=0;i<str.length();i++)
    {
        if(hash.find(str[i]) !=hash.end())
        {
         return str[i];
        }

    }
    return '$';
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
    string str,patt;
    cin>>str>>patt;
    cout<<get(str,patt)<<'\n';

    }

	return 0;
}

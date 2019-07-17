#include<iostream>
using namespace std;
#include<cstring>
bool isvowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='i'||ch=='o'||ch=='u')
        return true;
    else
        return false;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	char a[s.length()];
	int j=0;
	for(int i=0;i<s.length();i++)
	{
	    if(isvowel(s[i]))
	        a[j++]=s[i];
	}
  j=0;
	for(int i=s.length()-1;i>=0;i--)
	{
	    if(isvowel(s[i]))
	        s[i]=a[j++];
	}

	cout<<s<<'\n';
	}
	return 0;
}

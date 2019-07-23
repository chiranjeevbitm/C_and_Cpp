#include<iostream>
using namespace std;
#include<cstring>

bool ispal(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=s[s.length()-1-i])
        return false;
    }
    return true;
}

int main()
 {
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       string s;
       cin>>s;
       if(ispal(s))
            cout<<"Yes"<<"\n";
        else
            cout<<"No"<<"\n";

   }
	return 0;
}

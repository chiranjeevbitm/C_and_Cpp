#include<iostream>
using namespace std;
#define ll long long
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
  ll offset =0;
	while(k--)
	{
	 int typ,i;
	 cin>>typ>>i;
   i=i%n;
   if(typ==1)
   {
     offset = offset+(n-i);
   }
   else
   {
     cout<<s[(offset+i)%n]<<'\n';
   }

	}
}
	return 0;
}

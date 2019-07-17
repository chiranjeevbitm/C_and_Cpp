#include<iostream>
using namespace std;
#include<cstring>
void printPerm(string q,string a)
{
    if(q.length()==0)
    {
    cout<<a<<" ";
     return;
    }
    for(int i=0;i<q.length();i++)
    {
        char ch = q[i];
        string ros = q.substr(0,i)+q.substr(i+1);
        printPerm(ros,a+ch);
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	printPerm(s,"");
	cout<<'\n';
	}
	return 0;
}

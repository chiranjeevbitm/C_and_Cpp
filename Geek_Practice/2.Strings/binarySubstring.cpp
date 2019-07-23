#include<iostream>
using namespace std;
#include<cstring>

int NoOfSubstr(char str[],int k)
    {
    int m=2;
    int cnt=0;
    while(m<=k)
        {
        for(int i=0;i<=k-m;i++)
            if(str[i]=='1'&& str[m+i-1]=='1')
            cnt++;
        m++;
        }
    return cnt;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
  char *s=new char[n];
	cin>>s;
	int count =0 ;
	for(int i=0i<n;i++)
  if(s[i]==1)
  count++;

	cout<<(count*(count-1))/2<<'\n';
	}
	return 0;
}

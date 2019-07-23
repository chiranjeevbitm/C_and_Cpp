#include<iostream>
using namespace std;
#include<vector>

int minLen(string arr[],int n)
{
    int min = arr[0].length();
    for(int i=0;i<n;i++)
    {
        if(arr[i].length()<min)
        min= arr[i].length();
    }
    return min;
}
string lcp(string arr[],int n)
{
    int minstr = minLen(arr,n);
    string res="";
    char cur;

    for(int i=0;i<minstr;i++)
    {
        cur = arr[0][i];
         for(int j=0;j<n;j++)
            if(arr[j][i]!=cur)
                return res;
        res+=cur;
    }
    return res;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	string arr[4];
	for(int i=0;i<n;i++) cin>>arr[i];
  string ans = lcp(arr,n);
	cout<<ans<<"\n";
	}
	return 0;
}

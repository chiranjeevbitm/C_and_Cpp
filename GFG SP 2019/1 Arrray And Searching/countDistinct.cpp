#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{

		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}

void countDistinct(int arr[], int k, int n)
{

    int i=0,j=i+k-1;
while(j<n) {
int cnt=0;
unordered_map<int,int> m;
for(int a=i;a<=j;a++)
{
if(m[arr[a]]==0)
{
m[arr[a]]++;
cnt++;
}
else
{
m[arr[a]]++;
}
}
i++;j++;
cout<<cnt<<' ';

}
}

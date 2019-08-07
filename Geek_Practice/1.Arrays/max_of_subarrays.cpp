#include<iostream>
using namespace std;

#include<limits.h>

void findMax(int a[],int k,int n)
{
    int max = INT_MIN;
    for(int i=0;i<(n-k+1);i++)
    {
        max=a[i];
        for(int j=i;j<(k+i);j++)
         max = max>a[j] ? max:a[j];

        cout<<max<<" ";
        max = INT_MIN;
    }
    cout<<'\n';

}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n,k;
	cin>>n>>k;
  int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    findMax(a,k,n);

	}
	return 0;
}

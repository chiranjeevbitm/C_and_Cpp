#include<iostream>
using namespace std;
#include<cmath>
#include<climits>
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        int min = INT_MAX;
        int count=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            int m = abs(k-arr[i]);
            if(min>=m)
            {
                min=m;
                count=arr[i];

            }
        }
                cout<<count<<' ';
                cout<<'\n';
    }



	return 0;
}

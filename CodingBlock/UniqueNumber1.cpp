#include<iostream>
using namespace std;

int main() {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int res =0;
        for(int i=0;i<n;i++)
        {
        res = res^a[i];
        }
        cout<<res;

	return 0;
}

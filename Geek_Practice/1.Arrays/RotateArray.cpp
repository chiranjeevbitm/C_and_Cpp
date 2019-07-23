#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
 {
     int t;
     cin>> t;
     while(t--)
     {
         int n;
         cin>>n;
         vector<int> a(n);
         for(int i=0;i<n;i++)  cin>>a[i];
         int k;
         cin>>k;

          std::rotate(a.begin(),a.begin()+k,a.end());
           for(int i=0;i<n;i++)  cout<<a[i]<<" ";
           cout<<'\n';
         }
         cout<<"\n";

	return 0;
}

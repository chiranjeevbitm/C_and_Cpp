#include<iostream>
#include<vector>
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
         for(int i=0;i<n-1;i++)
         {
             if(a[i]>a[i+1])
                cout<<a[i+1]<<" ";
             else
                cout<<-1<<" ";
         }
         cout<<-1;
         std::cout  << '\n';
     }

     std::cout  << '\n';

	return 0;
}

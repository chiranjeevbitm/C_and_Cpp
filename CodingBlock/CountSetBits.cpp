#include<iostream>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
     int count =0;
     int n,k;
     cin>>n>>k;

     while(k>=n)
     {
         int i =k;
         k--;
         while(i)
        {
            if(i&1)
            count++;
            i=i/2;
        }
     }


	cout<<count<<'\n';
	}
	return 0;
}

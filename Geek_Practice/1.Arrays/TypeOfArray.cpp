#include<iostream>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int arr[n];
	int as=0,d=0;
	int temp =0 ;
	for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        temp=arr[0];

	    }
	for(int i=0;i<n;i++)
	{

	    if(arr[i+1]>temp)  temp =arr[i+1];
	    if(arr[i+1]>arr[i])
	    as++;
	    else
	    d++;
	}
	 if(as==(n-1)) cout<<temp<<" "<<"1"<<'\n';
	 if(d==(n-1)) cout<<temp<<" "<<"2"<<'\n';
	 if(as==(1)) cout<<temp<<" "<<"3"<<'\n';
	 if(d==(1)) cout<<temp<<" "<<"4"<<'\n';
	}
	return 0;
}

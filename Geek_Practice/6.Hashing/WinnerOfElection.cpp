#include<iostream>
#include<string.h>
using namespace std;
#include<limits.h>
#include <unordered_map>
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	unordered_map<string,int>win;;
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
	cin>>s;
	win[s]++;
	}
    int max=INT_MIN;
    string leader ="";
    for(auto i:win)
    {
    if(max < i.second)
    {
    max = i.second;
    leader = i.first;

    }

    if(i.second==max){
    if(i.first<leader)
        leader=i.first;
    }
    }
    cout<<leader<<" "<< max<<'\n';
	}
	return 0;
}

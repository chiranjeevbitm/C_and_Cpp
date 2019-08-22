#include<iostream>
using namespace std;

int Search(int a[],int l,int h,int key)
{
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(a[mid]==key) return mid;

    if(a[l]<=a[mid])
    {
        if(key>=a[l] && key<=a[mid])
        {
            return Search(a,l,mid-1,key);
        }
        return Search(a,mid+1,h,key);
    }
    if(key>=a[mid] && key<=a[h])
    {
        return Search(a,mid+1,h,key);
    }
    return Search(a,l,mid-1,key);

}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n,k;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)    cin>>a[i];
	cin>>k;
	cout<<Search(a,0,n-1,k)<<'\n';

	}
	return 0;
}

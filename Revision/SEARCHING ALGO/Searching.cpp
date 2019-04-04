#include<iostream>
using namespace std;
int LinSearch(int a[],int n,int x)
{
  for(int i= 0;i<n;i++)
    if(a[i]==x)
      return i;
  return -1;

}

int BinSearch(int a[],int l,int r,int x)
{
  if(r>=l)
  {
  int mid = (l+(r-1))/2;
  if(a[mid] == x)
  return mid;
  if(a[mid]>x)
   return BinSearch(a,l,mid-1,x);
  return BinSearch(a,mid+1,r,x);
  }
  return -1;
}

int InterPolationSearch(int a[],int n,int x)
{
  int l = 0;
  int h = n-1;
  while(h >= l && x>= a[l] && x<=a[h])
  {
  if(l == h)
  {
    if(a[l]==x)
      return l;
  return -1;
  }
  int pos = l+((x-a[l])*(h-l)/(a[h]-a[l]));
  if(a[pos] == x)
  return pos;
  if(a[pos]>x)
    l = pos+1;
  else
    h = pos-1;
  }
  return -1;
}

int ExponentialSearch(int a[],int n,int x)
{
  if (a[0] == x)
		return 0;

	int i = 1;
	while (i < n && a[i] <= x)
		i = i*2;

	return BinSearch(a, i/2, min(i, n), x);
}

int main()
{
  int a[]= {1,3,2,6,5,9,8};
  int n = sizeof(a)/sizeof(a[0]);
  //int res = LinSearch(a,n,5);
  //int res = BinSearch(a,0,n-1,5);
  //int res = InterPolationSearch(a,n,0);
  int res = ExponentialSearch(a,n,8);
  (res == -1)? std::cout << "Element is not present\n"
               : std::cout << "Element is present at index "<<res << '\n';;
}

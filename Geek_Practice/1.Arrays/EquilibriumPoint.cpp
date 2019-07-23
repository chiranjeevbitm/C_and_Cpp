#include<iostream>

int main()
{
int t,n;
int arr;
std::cin >> t;
while(t--)
{

  std::cin >> n;

  int arr[n];

 for(int i = 0;i< n;i++)    std::cin >> arr[i];
 int l = 0 ,r = n-1 , lsum =0 ,rsum =0;
  while(l<r)
  {
     if(lsum<rsum)   lsum +=arr[l++];
     else if(lsum>rsum)   rsum +=arr[r--];
     else  lsum +=arr[l++];

  }
  if(lsum == rsum)
  std::cout << l+1 << '\n';
  else
  std::cout << -1 << '\n';

}
return 0;
}

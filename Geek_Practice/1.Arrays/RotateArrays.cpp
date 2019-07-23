#include<iostream>
using namespace std;

void rotate(int arr[],int k,int n)
{
  int l,r;
  for(int i = 0;i<n;i+=k)
   {
     l = i;
     r = min(i+k-1,n-1);
     while(l<r)
     swap(arr[l++],arr[r--]);
   }
}

// void rotation(int[] arr, int k,int n) {
//
//   // if k exceeds nod
//   if (k > n)
//     k = k % n;
//
//   // if k is negative
//   if (k < 0)
//     k = k + n;
//   for (int i = n - k; i < n; i++)
//     cout<< arr[i] << " ";
//
//   for (int i = 0; i < k; i++)
//     cout<< arr[i] << " ";
//
// }

int main()
{
  long int n,k;
  int t;
  std::cin >>t ;
  while(t--)
  {
  std::cin >> n;
  std::cin >> k;

  int arr[n];
  for(int i=0;i<n;i++)
  std::cin >> arr[i];

  rotate(arr,k,n);
  for(int i=0;i<n;i++)
  std::cout << arr[i]<<' ';
  std::cout << '\n';
}
return 0;
}

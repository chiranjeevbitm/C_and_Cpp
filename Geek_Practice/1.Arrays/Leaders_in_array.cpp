#include<iostream>
using namespace std;
int main()
 {
   int t;
   std::cin >> t;
   while(t--)
   {
     int n;
     std::cin >> n;
     int arr[n];
     for(int i=0;i<n;i++) std::cin >>arr[i];

     int leader[n];
     leader[n-1] = 1;
     int max = n-1;
     for(int i=n-2;i>=0;i--)
     {
       if(arr[i]>=arr[max])
       {
         max = i;
         leader[i] = 1;
       }
       else leader[i] = 0;
     }
     for(int i=0;i<n;i++)
     {
       if(leader[i]==1) std::cout << arr[i] << ' ';
     }
     std::cout << '\n';
   }
return 0;
}

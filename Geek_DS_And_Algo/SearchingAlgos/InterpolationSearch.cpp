#include<iostream>
//#include<cmath>
//using namespace std;
/*
The idea of formula is to return higher value of pos
when element to be searched is closer to arr[hi]. And
smaller value when closer to arr[lo]
pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]

*/
int Interpolationsearch(int arr[],int x,int n){
int lo =0,hi = n-1;
while(lo<hi&& x>=arr[lo]&& x<= arr[hi]){
  int pos = lo + (((double)(hi-lo)/(arr[hi]-arr[lo]))*(x - arr[lo]));
  if(arr[pos]==x)
  return pos;
  if(arr[pos]<x)
  lo = pos+1;
  else
  hi = pos-1;
}
return -1;

}

int main(){
  int arr[] = {1,2,3,5,6,9,10};
  int x = 1;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = Interpolationsearch(arr,x,n);
  (result == -1)? std::cout << "Element not present in the array"
                : std::cout << "Element present at index :"<< result << '\n';

  return 0;
}

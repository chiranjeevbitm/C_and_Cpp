#include<iostream>
#include<cmath>
using namespace std;

int jumpsearch(int arr[],int x,int n){
  int jmp = sqrt(n);
  int prev = 0;
  while(arr[min(jmp,n)-1] < x){

    prev = jmp;
    jmp += sqrt(n);
    if(prev >= n)
    {
      return -1;
    }
  }
  while(arr[prev]<x){
    prev++;

  if(prev== min(jmp,n))
    return -1;

}
if(arr[prev]==x){
  return prev;
}
}z
int main(){
  int arr[] = {1,2,3,5,6,9,10};
  int x = 3;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = jumpsearch(arr,x,n);
  (result == -1)? std::cout << "Element not present in the array"
                : std::cout << "Element present at index :"<< result << '\n';

  return 0;
}

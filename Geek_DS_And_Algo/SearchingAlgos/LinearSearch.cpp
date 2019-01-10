#include<iostream>

int linsearch(int arr[],int size,int data){
  for(int i=0;i<size;i++){
    if(arr[i]== data){
      return i;
    }
}
    return -1;


}

int main(){
  int arr[] = {1,2,3,5,6,9,10};
  int data = 9;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = linsearch(arr,n,data);
  (result == -1)? std::cout << "Element not present in the array"
                : std::cout << "Element present at index :"<< result << '\n';

  return 0;
}

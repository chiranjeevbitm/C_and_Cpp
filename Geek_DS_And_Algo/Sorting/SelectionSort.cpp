#include<iostream>

void swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void SelectionSort(int arr[],int n){
  int i,j,min;
  for(i=0;i<n-1;i++){
    min = i;
    for(j = i+1; j<n;j++){
      if(arr[j]<arr[min])
      min = j;
    }
    swap(&arr[min],&arr[i]);
  }
}

void printarray(int arr[],int n){
  int i;
  for(i = 0;i<n;i++){
    std::cout << arr[i] << '\t';
  }
}


int main(){
  int arr[] = {2,4,1,8,3,10,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printarray(arr,n);
  SelectionSort(arr,n);
  std::cout << '\n'<< "After Sorting" << '\n';
  printarray(arr,n);
}

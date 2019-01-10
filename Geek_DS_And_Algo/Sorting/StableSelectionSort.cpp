#include<iostream>


void StableSelectionSort(int arr[],int n){
  int i,j,min;
  for(i=0;i<n-1;i++){
    min = i;
    for(j = i+1; j<n;j++){
      if(arr[j]<arr[min])
      min = j;
    }

    int key = arr[min];
        while (min > i)
        {
            arr[min] = arr[min - 1];
            min--;
        }
        arr[i] = key;
    }

}

void printarray(int arr[],int n){
  int i;
  for(i = 0;i<n;i++){
    std::cout << arr[i] << '\t';
  }
}


int main(){
  int arr[] = {2,4,4,1,8,3,10,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printarray(arr,n);
  StableSelectionSort(arr,n);
  std::cout << '\n'<< "After Sorting" << '\n';
  printarray(arr,n);
}

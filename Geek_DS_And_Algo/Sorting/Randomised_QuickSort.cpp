#include<iostream>
#include<cstdlib>
int r;
void swap(int *x,int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int arr[],int l,int h)
{
  int pivot = arr[h];
  int i = l-1;
  for(int j =l;j<h;j++)
  {
      if(arr[j]<=pivot)
      {
        i++;
        swap(&arr[i],&arr[j]);
      }
  }
  swap(&arr[i+1],&arr[h]);
  return(i+1);
}
int partition_r(int arr[],int l,int h){
    r = l+rand()%(h-l+1);

  //  std::cout << "This time Pivot choosen is :"<< r << '\n';
    swap(&arr[r],&arr[h]);
    return partition(arr,l,h);
}

void QuickSort(int arr[],int l,int h)
{
    if(l<h)
    {
      int partition_val = partition_r(arr,l,h);
      QuickSort(arr,l,partition_val-1);
      QuickSort(arr,partition_val+1,h);
    }
}

void printArray(int arr[],int size)
{
  for(int i = 0;i < size; i++)
    std::cout << arr[i] << ' ';
  std::cout  << '\n';
}

int main()
{
    int arr[] = {100,10,40,1,2,3,111,30,20,50,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Before sorting Array is : " << '\n';
    printArray(arr,n);
    QuickSort(arr,0,n-1);
    std::cout << "After QuickSort :" << '\n';
    printArray(arr,n);
  return 0;
}

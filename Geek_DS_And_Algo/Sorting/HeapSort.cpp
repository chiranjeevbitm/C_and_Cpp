#include<iostream>

void heapify(int arr[],int n,int i)
{
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;

  if(l<n && arr[l] >arr[largest])
  largest = l;

  if(r<n && arr[r]>arr[largest])
  largest = r;

  if(largest != i)
  {
    std::swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
  }
}
void heapsort(int arr[],int n)
{
  // Build heap (rearrange array)
  for(int i=n/2 -1;i>=0; i--)
  heapify(arr,n,i);

// One by one extract an element from heap
  for(int i = n-1;i>=0;i--)
  {

    // Move current root to end
    std::swap(arr[0],arr[i]);
    // call max heapify on the reduced heap
    heapify(arr,i,0);
  }
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapsort(arr, n);

    std::cout << "Sorted array is \n";
    printArray(arr, n);
}

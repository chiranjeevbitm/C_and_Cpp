#include<iostream>
#include<limits.h>
using namespace std;

int heap_size;

// void swap(int *a,int *b)
// {
//   int temp = *a;
//   *a=*b;
//   *b=temp;
//
// }

void max_heapify(int a[],int i)
{
  int l = 2*i+1;
  int r = 2*i+2;
  int largest = i;
  if(l<heap_size && a[l]>a[largest])
  {
  largest = l;
  }
  else
  {
  largest = i;
  }
  if(r<heap_size && a[r]>a[largest])
  {
  largest =r;
  }
  if(largest!=i)
  {
    int temp = a[i];
    a[i]=a[largest];
    a[largest]= temp;

    max_heapify(a,largest);
  }

}

void build_max_heap(int a[],int n)
{
  int i = (n/2)-1;
  for(int j=i;j>=0;j--)
  {
    max_heapify(a,j);
  }
}

//extract min

int main()
{
  int a[] = {5,8,10,9,7,2};
  heap_size = 6;
  build_max_heap(a,heap_size);
  for(int i=0;i<6;i++)  cout<<a[i]<<" ";
}

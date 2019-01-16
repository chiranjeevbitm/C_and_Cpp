#include<iostream>
#include<stdlib.h>
int kadanes(int arr[],int size)
{
  int currntMax = arr[0];
  int globalMax =arr[0];
  int i;
  for(i=1;i<size;i++)
  {
    currntMax = std::max(arr[i],arr[i]+currntMax);
    globalMax = std::max(currntMax,globalMax);

  }
  std::cout << globalMax << '\n';
  return 0;

}
int main()
{
  int t,size;
  std::cin >>t ;
  while(t--)
  {
  std::cin >> size;
  int arr[size];
  for(int i=0;i<size;i++)
  std::cin >> arr[i];
  // int arr[] = {1,2,3,-2,5};
  // int n= sizeof(arr)/sizeof(arr[0]);
  kadanes(arr,size)<<'\n';
}
return 0;
}

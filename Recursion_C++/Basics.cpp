#include <iostream>
#include<list>
#include<string.h>
using namespace std;

void printCol(int col, int n) {
  if (col > n)
    return;

  cout << "*";
  printCol(col + 1, n);
}
void printRow(int row, int n) {
  if (row > n)
    return;
  cout << "*" << '\n';
  printCol(row + 1, n);
}
void printBox(int row, int col, int n) {
  if (row > n)
    return;
  if (col > n) {
    std::cout << '\n';
    printBox(row + 1, 1, n);
    return;
  }
  cout << "* ";
  printBox(row, col + 1, n);
}

void Triangle(int row, int col, int n) {
  if (row > n)
    return;
  if (col > row) {
    std::cout << '\n';
    Triangle(row + 1, 1, n);
    return;
  }
  cout << "* ";
  Triangle(row, col + 1, n);
}

void Triangle1(int row, int col, int n) {
  if (row > n)
    return;
  if (col > row) {
    Triangle1(row + 1, 1, n);
    if (row != n)
      std::cout << '\n';
    return;
  }

  Triangle1(row, col + 1, n);
  cout << "* ";
}

void BubbleSort(int arr[],int si,int ei)
{

  //base case
  if(ei==0)
  return;
   if(si==ei)
   {
   BubbleSort(arr,0,ei-1);
   return;
   }

  if(arr[si]>arr[si+1])
  {
    int temp=arr[si];
    arr[si]=arr[si+1];
    arr[si+1 ]=temp;
  }
  BubbleSort(arr,si+1,ei);
}


int main()
{
  // Triangle1(1, 1, 5);
  int arr[] = {40,20,10,90,30};
  //int n = arr.size();
  //BubbleSort(arr,0,4);
  //for(int val : arr)  std::cout << val << ' ';
  std::cout << getSS("abc");
}

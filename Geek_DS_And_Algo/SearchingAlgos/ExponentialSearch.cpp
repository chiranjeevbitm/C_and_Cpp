#include<iostream>

int binarySearch(int arr[], int, int, int);

int exponentialSearch(int arr[], int n, int x)
{

    if (arr[0] == x)
        return 0;

     int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;

    return binarySearch(arr, i/2, std::min(i, n), x);
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}


int main(){
  int arr[] = {1,2,3,5,6,9,10};
  int x = 9;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = exponentialSearch(arr,n,x);
  (result == -1)? std::cout << "Element not present in the array"
                : std::cout << "Element present at index :"<< result << '\n';

  return 0;
}

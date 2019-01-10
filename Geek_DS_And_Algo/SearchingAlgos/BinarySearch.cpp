#include<iostream>
int binarySearchRec(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearchRec(arr, l, mid - 1, x);

        return binarySearchRec(arr, mid + 1, r, x);
    }

    return -1;
}
int binarySearchLin(int arr[], int l, int r, int x)
{
    while (l<=r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;
        else
        r = mid-1;

    }

    return -1;
}

int main(){
  int arr[] = {1,2,3,5,6,9,10};
  int x = 3;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearchRec(arr,0,n-1,x);
  (result == -1)? std::cout << "Element not present in the array"
                : std::cout << "Element present at index :"<< result << '\n';

  return 0;
}

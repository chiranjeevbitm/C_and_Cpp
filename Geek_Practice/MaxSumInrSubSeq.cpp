#include<iostream>

int maxSumIs(int arr[],int n)
{
  int i, j, max = 0;
    int msis[n];

    /* Initialize msis values
       for all indexes */
    for ( i = 0; i < n; i++ )
        msis[i] = arr[i];

    /* Compute maximum sum values
       in bottom up manner */
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if (arr[i] > arr[j] &&
                msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];

    /* Pick maximum of
       all msis values */
    for ( i = 0; i < n; i++ )
        if ( max < msis[i] )
            max = msis[i];
  
    return max;
}


int main()
{
int t,n;
std::cin >> t;
while(t--)
{
  std::cin >> n;
  int arr[n];
  for(int i = 0;i< n;i++)    std::cin >> arr[i];
  std::cout << maxSumIs(arr,n)<<'\n';
}
}

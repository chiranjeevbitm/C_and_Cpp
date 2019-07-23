#include <algorithm>
#include <climits>
#include <iostream>

int findMaxDiff(int arr[], int n, int m) {
  if (m == 0 || n == 0)
    return 0;

  sort(arr, arr + n);

  if (n < m)
    return -1;
  int min_diff = INT_MAX;
  int first = 0, last = 0;
  for (int i = 0; i + m - 1 < n; i++) {
    int diff = arr[i + m - 1] - arr[i];
    if (diff < min_diff) {
      diff = min_diff;
      first = i;
      last = i + m - 1;
    }
  }
  return (arr[last] - arr[first]);
}

int main() {
  int n, m;
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      std::cin >> arr[i];
    std::cin >> m;
    findMaxDiff(arr, n, m);
    std::cout << '\n';
  }
  return 0;
}

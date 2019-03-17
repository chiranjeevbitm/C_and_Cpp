#include <iostream>
using namespace std;
int main() {

  int t;
  std::cin >> t;
  int n;
  while (t--) {
    std::cin >> n;
    int arr[n], flag = 0;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
      if (!flag)
        if (arr[i] > arr[i + 1])
          swap(arr[i], arr[i + 1]);
      if (flag)
        if (arr[i] < arr[i + 1])
          swap(arr[i], arr[i + 1]);
      flag = !flag;
    }
    for (int i = 0; i < n; i++)
      cout << arr[i] << ' ';
    cout << "\n";
  }
}

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
    for (int i = 1; i < n; i++) {
      if (arr[i - 1] < arr[i] && arr[i + 1] > arr[i]) {
        std::cout << arr[i] << ' ';
        flag++;
        return 0;
      }
    }
    if (flag == 0)
      cout << "-1";

    cout << "\n";
  }
}

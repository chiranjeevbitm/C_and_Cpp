#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
int comp(string x, string y) {
  string xy = x.append(y);
  string yx = y.append(x);

  return xy.compare(yx) > 0 ? 1 : 0;
}

void printlargest(vector<string> arr) {
  sort(arr.begin(), arr.end(), comp);
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    printlargest(arr);
    std::cout << '\n';
  }
  return 0;
}

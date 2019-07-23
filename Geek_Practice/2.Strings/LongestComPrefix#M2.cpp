#include <iostream>
#include <string.h>

using namespace std;
int findMinLen(string arr[], int n) {
  int min = arr[0].length();
  for (int i = 0; i < n; i++)
    if (arr[i].length() < min)
      min = arr[i].length();

  return (min);
}
string comPrefix(string arr[], int n) {
  int minlen = findMinLen(arr, n);
  string res;
  char cur;
  for (int i = 0; i < minlen; i++) {
    cur = arr[0][i];
    for (int j = 0; j < n; j++)
      if (arr[j][i] != cur)
        return res;

    res.push_back(cur);
  }
  return (res);
}

int main() {
  // code
  int t;
  cin >> t;
  string res;
  while (t--) {
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    // int l = sizeof() / sizeof(str[0]);
    res = comPrefix(arr, n);
    if (res.length() == 0)
      cout << "-1" << '\n';
    else
      cout << res << '\n';
  }
  return 0;
}

#include <iostream>
#include <string.h>

using namespace std;

char *removeDup(char str[], int n) {
  int index = 0;
  for (int i = 0; i < n; i++) {
    int j;
    for (j = 0; j < i; j++)
      if (str[i] == str[j])
        break;
    if (j == i)
      str[index++] = str[i];
  }
  return str;
}

int main() {
  // code
  int t;
  cin >> t;
  string res;
  while (t--) {
    char str[1000];
    cin >> str;
    int n = sizeof(str) / sizeof(str[0]);
    res = removeDup(str, n);
    cout << res;
  }
  return 0;
}

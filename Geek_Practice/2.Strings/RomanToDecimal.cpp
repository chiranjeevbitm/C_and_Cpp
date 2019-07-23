#include <iostream>
using namespace std;

int value(char r) {
  if (r == 'I')
    return 1;
  if (r == 'V')
    return 5;
  if (r == 'X')
    return 10;
  if (r == 'L')
    return 50;
  if (r == 'C')
    return 100;
  if (r == 'D')
    return 500;
  if (r == 'M')
    return 1000;

  return -1;
}

int romToDec(string &str) {
  int res = 0;
  int s1, s2;
  // Traverse given input
  for (int i = 0; i < str.length(); i++) {

    if (i == str.length() - 1) {
      s1 = value(str[i]);
      res = res + s1;
      return res;
    } else {
      s1 = value(str[i]);
      s2 = value(str[i + 1]);
      if (s1 >= s2)
        res = res + s1;
      else
        res = res - s1;
    }
  }
}
int main() {
  int t;
  string roman;
  cin >> t;
  while (t--) {
    cin >> roman;
    cout << romToDec(roman) << '\n';
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
string clockwise(string str) {
  string s;
  int len = str.length();
  int i = len - 2;
  while (i < 2 * len - 2) {
    s += str[(i) % len];
    i++;
  }
  return s;
}
string Anticlockwise(string str) {
  string s;
  int i = 0;
  int len = str.length();
  while (i < len) {
    s += str[(i + 2) % len];
    i++;
  }
  return s;
}

int main() {
  int t;
  cin >> t;
  string a, b;
  while (t--) {

    cin >> a;
    cin >> b;
    if (a.compare(clockwise(b)) == 0 || a.compare(Anticlockwise(b)) == 0) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    // cout << '\n';
  }
  return 0;
}

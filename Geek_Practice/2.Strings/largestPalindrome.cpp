#include <iostream>
#include <string.h>
using namespace std;
void printsubstr(string str, int l, int h) {
  for (int i = l; i < h; i++) {
    std::cout << str[i];
  }
}

int logestpalstr(string str) {
  int maxlen = 1;
  int start = 0;
  //  int len = str.lenght();
  int l, h;

  for (int i = 1; i < str.size(); ++i) {
    // for even length palindromes
    // center points as i-1 and i
    l = i - 1;
    h = i;
    while (l >= 0 && h < str.size() && str[l] == str[h]) {
      if (h - l + 1 > maxlen) {
        start = l;
        maxlen = h - l + 1;
      }
      --l;
      ++h;
    }
    // for odd length palindromes
    // center points as i-1 and i+1
    l = i - 1;
    h = i + 1;
    while (l >= 0 && h < str.size() && str[l] == str[h]) {
      if (h - l + 1 > maxlen) {
        start = l;
        maxlen = h - l + 1;
      }
      --l;
      ++h;
    }
  }
  printsubstr(str, start, start + maxlen);
  return maxlen;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str, res;
    cin >> str;
    logestpalstr(str);
    cout << '\n';
  }
  return 0;
}

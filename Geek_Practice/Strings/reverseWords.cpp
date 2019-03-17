#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

void rever(string s) {
  string str, temp, ans;
  getline(cin, str);
  int l = str.length();

  for (int i = 0; i < l; i++) {
    temp = "";
    while (str[i] != ' ' && i < l) {
      temp += str[i];
      i++;
    }
    ans = temp + ans;
    if (i < l)
      ans = str[i] + ans;
  }
  cout << ans;

  return 0;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    string s;
    std::cin >> s;
    reverse(s.begin(), s.end());
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '.') {
        temp += s[i];
      } else {
        reverse(temp.begin(), temp.end());
        std::cout << temp << '.';
        temp = "";
      }
    }
    reverse(temp.begin(), temp.end());
    std::cout << temp << '\n';
  }
  return 0;
}

#include <iostream>
#include <string.h>

using namespace std;

string RecurDup(string str) {
  int n = str.length();
  string temp;
  if (str[0] != str[1]) {
    temp += str[0];
  }
  int i = 1;
  while (i < n) {
    if (str[i] != str[i - 1] && str[i] != str[i + 1]) {
      temp += str[i];
    }
    i++;
  }
  if (temp.length() == 0) {
    return temp;
  }
  if (temp.length() != str.length()) {
    return RecurDup(temp);
  }
  return temp;
}

int main() {
  // code
  int t;
  cin >> t;
  while (t--) {
    string str, res;
    cin >> str;
    res = RecurDup(str);

    cout << res << '\n';
  }
  return 0;
}

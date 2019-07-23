#include <iostream>
#include <string.h>
#include <unordered_set>

using namespace std;

int main() {
  // code
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i, count = 0, max = 0, j = 0;
    unordered_set<char> s1;
    for (i = 0; i <= s.length(); i++) {
      if (s1.find(s[i]) == s1.end() && s[i] != '\0') {
        s1.insert(s[i]);
        count++;
      } else {
        if (count >= max) {
          max = count;
        }

        s1.erase(s1.begin(), s1.end());
        count = 1;
        j++;
        i = j;
        s1.insert(s[i]);
      }
    }
    cout << max << '\n';
  }
  return 0;
}

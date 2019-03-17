#include <iostream>
#include <string>
using namespace std;
int cnt = 0;

void printPermutation(string s, string decision) {
  // print permuatation prints all the permutations of a string s after
  // appending them to res

  if (s.size() == 0) {
    cout << decision << " ";
    return;
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i) {
    string rem = s.substr(0, i) + s.substr(i + 1);
    string ans = decision + s[i];
    printPermutation(rem, ans);
  }
}

int main() {
  int t, n, i;
  cin >> t;
  while (t != 0) {

    string s;
    cin >> s;

    printPermutation(s, "");
    std::cout << '\n';
    t--;
  }
}

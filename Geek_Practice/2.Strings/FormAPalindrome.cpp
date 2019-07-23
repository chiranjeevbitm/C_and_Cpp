#include <iostream>
#include <string.h>

using namespace std;
bool isPal(string str, int st, int end) {
  while (st < end) {
    if (str[st] != str[end])
      return false;

    st++;
    end--;
  }
  return true;
}
int minInsertion(string str, int n) {
  for (int i = n - 1; i >= 0; i--) {
    if (isPal(str, 0, i))
      return (n - i - 1);
  }
  return 0;
}

int main() {
  // code
  int t;

  cin >> t;
  while (t--) {
    string X;
    cin >> X;
    int l1 = X.length();
    int result = minInsertion(X, l1);
    cout << result;
    cout << '\n';
  }
  return 0;
}

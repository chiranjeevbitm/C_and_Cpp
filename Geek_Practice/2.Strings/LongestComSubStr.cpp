#include <iostream>
#include <string.h>

using namespace std;
string X, Y;

int maxl(int a, int b) { return (a > b) ? a : b; }

int lcs(int i, int j, int c) {
  if (i == 0 || j == 0)
    return c;
  if (X[i - 1] == Y[j - 1]) {
    c = lcs(i - 1, j - 1, c + 1);
  }
  c = maxl(c, maxl(lcs(i, j - 1, 0), lcs(i - 1, j, 0)));
  return c;
}

int main() {
  // code
  int t, l1, l2;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cin >> X;
    cin >> Y;
    l1 = X.length();
    l2 = Y.length();
    cout << lcs(l1, l2, 0);
    cout << '\n';
  }
  return 0;
}

#include <iostream>
#include <string.h>

using namespace std;
string X, Y;

int maxl(int a, int b) { return (a > b) ? a : b; }

int lcs(char *X, char *Y, int m, int n) {
  int LCSuf[m + 1][n + 1];
  int res = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCSuf[i][j] = 0;

      else if (X[i - 1] == Y[i - 1]) {
        LCSuf[i][j] = LCSuf[i - 1][j - 1] + 1;
        res = max(res, LCSuf[i][j]);
      } else
        LCSuf[i][j] = 0;
    }
  }
  return res;
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
    cout << lcs(X, Y, l1, l2);
    cout << '\n';
  }
  return 0;
}

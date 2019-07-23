#include <climits>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, max = INT_MIN;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    int lcs[n + 1][m + 1];
    // putting 0 at every location of lcs
    memset(lcs, 0, sizeof(lcs[0][0]) * (n + 1) * (m + 1));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1])
          lcs[i][j] = 1 + lcs[i - 1][j - 1];
        if (max < lcs[i][j])
          max = lcs[i][j];
      }
    cout << max << "\n";
  }
  return 0;
}

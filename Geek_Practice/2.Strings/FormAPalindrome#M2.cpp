#include <climits>
#include <iostream>

#include <string.h>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int FM(string str, int l, int h) {
  // Base Cases
  if (l > h)
    return INT_MAX;
  if (l == h)
    return 0;
  if (l == h - 1)
    return (str[l] == str[h]) ? 0 : 1;

  // Check if the first and last characters are
  // same. On the basis of the comparison result,
  // decide which subrpoblem(s) to call
  return (str[l] == str[h]) ? FM(str, l + 1, h - 1)
                            : (min(FM(str, l, h - 1), FM(str, l + 1, h)) + 1);
}

int FM_DP_fast(string str, int n) {
  // Create a table of size n*n. table[i][j]
  // will store minimum number of insertions
  // needed to convert str[i..j] to a palindrome.
  int table[n][n], l, h, gap;

  // Initialize all table entries as 0
  memset(table, 0, sizeof(table));

  // Fill the table
  for (gap = 1; gap < n; ++gap)
    for (l = 0, h = gap; h < n; ++l, ++h)
      table[l][h] = (str[l] == str[h])
                        ? table[l + 1][h - 1]
                        : (min(table[l][h - 1], table[l + 1][h]) + 1);

  // Return minimum number of insertions for
  // str[0..n-1]
  return table[0][n - 1];
}

int main() {
  // code
  int t;

  cin >> t;
  while (t--) {
    string X;
    cin >> X;
    int l1 = X.length();
    int result = FM_DP_fast(X, l1);
    cout << result;
    cout << '\n';
  }
  return 0;
}

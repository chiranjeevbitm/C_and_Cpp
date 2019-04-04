#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;

string longest_common_prefix(vector<string> &vec) {
  if (vec.size() == 0) {
    return "-1";
  } else {
    string lcs = vec[0];
    for (int i = 1; i < vec.size(); i++) {
      string cur = vec[i];
      int j = 0;
      while (j < lcs.length() && j < cur.length() && lcs[j] == cur[j]) {
        j++;
      }
      if (j == 0) {
        return "-1";
      }
      lcs = lcs.substr(0, j);
    }
    return lcs;
  }
}
int main() {
  // code
  int t;
  cin >> t;
  while (t != 0) {
    int n;
    cin >> n;
    vector<string> vec;
    string temp, cur;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      vec.push_back(temp);
    }
    string res = longest_common_prefix(vec);
    cout << res << endl;
    t--;
  }
  return 0;
}

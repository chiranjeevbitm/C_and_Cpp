#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_CHAR = 26;

// method 1
void angram(string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a.compare(b) == 0)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}

// method 2
bool angramfast(string a, string b) {
  int la = a.length();
  int lb = b.length();
  if (la != lb)
    return false;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < n1; i++)
    if (a[i] != b[i])
      return false;
    else
      return true;
}

// Method 3 (Fastest)

// Function to check if str1 and str2 are k-anagram
// or not
bool areKAnagrams(string str1, string str2, int k) {
  // If both strings are not of equal
  // length then return false
  int n = str1.length();
  if (str2.length() != n)
    return false;

  int hash_str1[MAX_CHAR] = {0};

  // Store the occurrence of all characters
  // in a hash_array
  for (int i = 0; i < n; i++)
    hash_str1[str1[i] - 'a']++;

  // Store the occurrence of all characters
  // in a hash_array
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (hash_str1[str2[i] - 'a'] > 0)
      hash_str1[str2[i] - 'a']--;
    else
      count++;

    if (count > k)
      return false;
  }

  // Return true if count is less than or
  // equal to k
  return true;
}

int main() {
  int t;
  string a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (angramfast(a, b))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}

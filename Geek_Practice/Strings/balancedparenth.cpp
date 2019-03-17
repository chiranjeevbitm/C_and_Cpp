#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string expr) {
  stack<char> s;
  char x;

  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
      s.push(expr[i]);
      continue;
    }
    if (s.empty())
      return false;

    switch (expr[i]) {
    case ')':
      x = s.top();
      s.pop();
      if (x == '{' || x == '[')
        return false;
      break;

    case '}':
      x = s.top();
      s.pop();
      if (x == '(' || x == '[')
        return false;
      break;

    case ']':
      x = s.top();
      s.pop();
      if (x == '{' || x == '(')
        return false;
      break;
    }
  }
  return (s.empty());
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    string str;
    std::cin >> str;

    if (isBalanced(str))
      cout << "balanced" << '\n';
    else
      cout << "not balanced" << '\n';
  }
  return 0;
}

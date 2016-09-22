// Check brackets in the code
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

void isBalanced(string& str) {
  stack<char> s;
  for (int i = 0; i < str.size(); ++i) {
    char c = str[i];
    if (c == '(' || c == '{' || c == '[')
      s.push(c);
    else if (c == ')' || c == '}' || c == ']'){
      if (s.empty()) {
        cout << (i + 1) << endl;
        return;
      }
      char top = s.top();
      if ((top == '[' && c != ']') ||
          (top == '{' && c != '}') ||
          (top == '[' && c != ']')) {
          cout << (i + 1) << endl;
          return;
      } else
        s.pop();
    }
  }
  if (s.empty()) cout << "Success" << endl;
  else cout << 1 << endl;
}

int main() {
  string str; cin >> str;

  isBalanced(str);

  return 0;
}


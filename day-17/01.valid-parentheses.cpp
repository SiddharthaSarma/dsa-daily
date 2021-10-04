class Solution {
public:
  bool isValid(string str) {
    stack<char> s;
    map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
    for (char c: str) {
      if (c == ')' || c == '}' || c == ']') {
        if (!s.empty() && s.top() == m[c]) {
          s.pop();
        } else {
          return false;
        }
      } else {
        s.push(c);
      }
    }
    if (s.size()) {
      return false;
    }
    return true;
  }
};

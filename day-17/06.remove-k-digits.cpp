class Solution {
 public:
  string removeKdigits(string num, int k) {
    stack<char> s;
    if (num.size() == k) {
      return "0";
    }
    for (char c : num) {
      if (s.empty() && c != '0') {
        s.push(c);
        continue;
      }
      while (!s.empty() && s.top() > c && k > 0) {
        s.pop();
        k--;
      }
      if (c != '0' || !s.empty()) {
        s.push(c);
      }
    }
    while (!s.empty() && k--) {
      s.pop();
    }
    string res;
    while (!s.empty()) {
      res = s.top() + res;
      s.pop();
    }
    return res.size() ? res : "0";
  }
};

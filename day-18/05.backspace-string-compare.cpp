class Solution {
public:
  bool backspaceCompare(string s, string t) {
    stack<char> first;
    stack<char> second;
    for (char c: s) {
      if (c == '#' && !first.empty()) {
        first.pop();
      } else if (c != '#') {
        first.push(c);
      }
    }
    for (char c: t) {
      if (c == '#' && !second.empty()) {
        second.pop();
      } else if (c != '#') {
        second.push(c);
      }
    }
    string res;
    string res1;
    while (!first.empty()) {
      res = first.top() + res;
      first.pop();
    }
    while (!second.empty()) {
      res1 = second.top() + res1;
      second.pop();
    }
    return res == res1;
  }
};

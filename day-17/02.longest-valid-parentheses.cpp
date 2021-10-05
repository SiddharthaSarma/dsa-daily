class Solution {
public:
  int longestValidParentheses(string str) {
    int res = 0;
    stack<int> index;
    stack<char> s;
    index.push(-1);
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(') {
      	s.push(str[i]);
      	index.push(i);
      } else {
      	if (!s.empty() && s.top() == '(') {
      		s.pop();
      		index.pop();
      		res = max(res, i - index.top());
      	} else {
      		index.push(i);
      	}
      }
    }
    return res;
  }
};

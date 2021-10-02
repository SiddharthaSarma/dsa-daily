// https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<long> s;
    for (int i = 2*n - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= arr[i  % n]) {
        s.pop();
      }
      if (i < n) {
        if (s.empty()) {
          result[i] = -1;
        } else {
          result[i] = s.top();
        }
      }
      s.push(arr[i % n]);
    }
    return result;
  }
};

// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && arr[s.top()] <= arr[i]) {
        s.pop();
      }
      if (s.empty()) {
        res[i] = 0;
      } else {
        res[i] = s.top() - i;
      }
      s.push(i);
    }
    return res;
  }
};

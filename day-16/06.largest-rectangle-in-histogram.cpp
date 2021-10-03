class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
        s.pop();
      }
      if (s.empty()) {
        left[i] = 0;
      } else {
        left[i] = s.top() + 1;
      }
      s.push(i);
    }
    while (!s.empty()) {
      s.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
        s.pop();
      }
      if (s.empty()) {
        right[i] = n - 1;
      } else {
        right[i] = s.top() - 1;
      }
      s.push(i);
    }
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxVal = max(maxVal, (right[i] - left[i] + 1) * heights[i]);
    }
    return maxVal; 
  }
};

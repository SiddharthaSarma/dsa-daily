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
  int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>> intM;
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
      vector<int> temp;
      for (int j = 0; j < n; j++) {
        int k = matrix[i][j] == '1' ? 1 : 0;
        temp.push_back(k);
      }
      intM.push_back(temp);
    }
    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        intM[i][j] += intM[i][j] == 1 ? intM[i - 1][j] : 0;
      }
    }
    int maxArea = INT_MIN;
    for (int i = 0; i < m; i++) {
      maxArea = max(maxArea, largestRectangleArea(intM[i]));
    }
    return maxArea;
  }
};

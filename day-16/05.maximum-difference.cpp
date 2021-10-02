// https://practice.geeksforgeeks.org/problems/maximum-difference/1#
#include <iostream>
#include <stack>
#include <vector>

#include "limits.h"

using namespace std;

class Solution {
 public:
  int findMaxDiff(int arr[], int n) {
    stack<int> s;
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
      while (!s.empty() && s.top() >= arr[i]) {
        s.pop();
      }
      if (s.empty()) {
        left[i] = 0;
      } else {
        left[i] = s.top();
      }
      s.push(arr[i]);
    }
    while (!s.empty()) {
      s.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && s.top() >= arr[i]) {
        s.pop();
      }
      if (s.empty()) {
        right[i] = 0;
      } else {
        right[i] = s.top();
      }
      s.push(arr[i]);
    }

    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxVal = max(maxVal, abs(left[i] - right[i]));
    }
    return maxVal;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution obj;
    int val = obj.findMaxDiff(arr, n);
    cout << val << endl;
  }
}

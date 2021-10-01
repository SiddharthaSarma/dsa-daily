#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> nextGreaterElement(vector<long long>& arr, int n) {
    vector<long long> result(n);
    stack<long> s;
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= arr[i]) {
        s.pop();
      }
      if (s.empty()) {
        result[i] = -1;
      } else {
        result[i] = s.top();
      }
      s.push(arr[i]);
    }
    return result;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution obj;
    vector<long long> res = obj.nextGreaterElement(arr, n);
    for (auto& i : res) {
      cout << i << " ";
    }
    cout << endl;
  }
}

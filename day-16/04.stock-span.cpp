#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> calculateSpan(int price[], int n) {
    vector<int> res(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
      while (!s.empty() && price[s.top()] <= price[i]) {
        s.pop();
      }
      if (s.empty()) {
        res[i] = i + 1;
      } else {
        res[i] = i - s.top();
      }
      s.push(i);
    }
    return res;
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
    vector<int> res = obj.calculateSpan(arr, n);
    for (auto& i : res) {
      cout << i << " ";
    }
    cout << endl;
  }
}

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
 public:
  static int countRev(string s) {
    if (s.size() & 1) {
      return -1;
    }
    int left = 0;
    int right = 0;
    for (char c : s) {
      if (c == '{') {
        left++;
      } else {
        if (left == 0) {
          right++;
        } else {
          left--;
        }
      }
    }
    return (ceil(left / 2.0) + ceil(right / 2.0));
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << Solution::countRev(s) << endl;
  }
}

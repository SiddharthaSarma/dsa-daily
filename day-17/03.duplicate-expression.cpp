#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
 	static void showStack(stack<char> s) {
 		while (!s.empty()) {
 			cout << s.top();
 			s.pop();
 		}
 		cout << endl;
 	}
  static bool isDuplicateParenthesisFound(string str) {
    stack<char> s;
    for (char c : str) {
      if (c != ')') {
        s.push(c);
      } else {
        int count = 0;
        while (!s.empty() && s.top() != '(') {
          count++;
          s.pop();
        }
        s.pop();
        if (count == 0) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << Solution::isDuplicateParenthesisFound(s) << endl;
  }
}

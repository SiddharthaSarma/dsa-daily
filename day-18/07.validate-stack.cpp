class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int j = 0;
    stack<int> s;
    for (auto& p: pushed){
      s.push(p);
      while (!s.empty() && s.top() == popped[j]) {
        s.pop();
        j++;
      }
    }
    return s.empty();
  }
};

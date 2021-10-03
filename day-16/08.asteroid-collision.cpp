class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    for (int i = 0; i < asteroids.size(); i++) {
      if (asteroids[i] > 0) {
        s.push(asteroids[i]);
      } else {
        while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
          s.pop();
        }
        if (s.empty() || s.top() < 0) {
          s.push(asteroids[i]);
        } else if (s.top() == abs(asteroids[i])) {
          s.pop();
        }
      }
    }
    vector<int> res(s.size());
    for (int i = res.size() - 1; i >= 0; i--) {
      res[i] = s.top();
      s.pop();
    }
    return res;
  }
};

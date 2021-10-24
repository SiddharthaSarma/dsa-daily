class Solution {
public:
  int carFleet(int target, vector<int>& p, vector<int>& s) {
    map<float, float> cars;
    for (int i = 0; i < p.size(); i++) {
      cars.insert({-p[i], s[i]});
    }
    float lastTime = -1.0;
    int fleet = 0;
    for (const auto& car: cars) {
      float time = (target + car.first) / car.second;
      if (time > lastTime) {
        lastTime = time;
        fleet++;
      }
    }
    return fleet;
  }
};

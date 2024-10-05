#include <array>
#include <algorithm>

#ifndef LAB1_MYLIB_HEALTHMANAGER_H_
#define LAB1_MYLIB_HEALTHMANAGER_H_



enum class SegmentHealth {
  kDestroyed = 0,
  kInjured = 1,
  kUntouched = 2,
};

class HealthManager {
 public:
  HealthManager();



  void DecreaseHealth(int value);
  void IncreaseHealth(int value);

  SegmentHealth get_health_();
  void set_health_(int value);
/*
  SegmentHealth operator + (int value);
  SegmentHealth operator - (int value);
*/
 private:
  SegmentHealth health_;

  std::array<SegmentHealth, 3> kHealthOrder = {SegmentHealth::kDestroyed, SegmentHealth::kInjured, SegmentHealth::kUntouched};


};

#endif

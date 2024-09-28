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

/*
  void DecreaseHealth();
  void IncreaseHealth();
*/
  SegmentHealth get_health_();

  SegmentHealth operator + (int value);
  SegmentHealth operator - (int value);

 private:
  SegmentHealth health_;

  const std::array<SegmentHealth, 3> kHealthOrder = {SegmentHealth::kDestroyed, SegmentHealth::kInjured, SegmentHealth::kUntouched};


};

#endif

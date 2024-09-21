#ifndef LAB1_MYLIB_HEALTHMANAGER_H_
#define LAB1_MYLIB_HEALTHMANAGER_H_

#include <array>
#include <algorithm>

enum class SegmentHealth {
  kDestroyed = 0,
  kInjured,
  kUntouched,
};

class HealthManager {
 public:
  HealthManager();

  void DecreaseHealth();

  void IncreaseHealth();

  SegmentHealth get_health_();


 private:
  SegmentHealth health_;

  const std::array<SegmentHealth, 3> colorOrder = {SegmentHealth::kDestroyed, SegmentHealth::kInjured, SegmentHealth::kUntouched};


};

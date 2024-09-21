#include "HealthManager.h"

HealthManager::HealthManager() : health_{SegmentHealth::kUntouched} {}

void HealthManager::DecreaseHealth() {
  auto it = std::find(colorOrder.begin(), colorOrder.end(), health_);

  if (it != colorOrder.begin()) {
    --it;
    health_ = *it;
  }
}

void HealthManager::IncreaseHealth() {
  auto it = std::find(colorOrder.begin(), colorOrder.end(), health_);

  if (it != colorOrder.end() - 1) {
    ++it;
    health_ = *it;
  }
}

SegmentHealth HealthManager::get_health_() {
  return health_;
}
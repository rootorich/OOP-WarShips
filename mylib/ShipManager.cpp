#include "ShipManager.h"


ShipManager::ShipManager(size_t count, std::vector<ShipSize> sizes) {
  count_ = count;
  for(auto size : sizes) {
    ships_.emplace_back(size);
  }
}

void ShipManager::AddShip(ShipSize size) {
  ships_.emplace_back(size);
  count_++;
}

void ShipManager::HitShip(size_t segment_number, size_t damage) {
  ships_[segment_number].segments_health_
}


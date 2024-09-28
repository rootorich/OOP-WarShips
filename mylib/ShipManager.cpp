#include "ShipManager.h"


ShipManager::ShipManager(std::vector<ShipSize> sizes, std::vector<ShipOrientation> orientations) {
  for(auto size : sizes) {
    ships_.emplace_back(size);
  }
}

void ShipManager::AddShip(ShipSize size) {
  ships_.emplace_back(size);
}

/*
void ShipManager::HitShip(size_t segment_number, size_t damage) {
  ships_[segment_number].segments_health_ - damage;
}
*/

4 2 3 1 2 1 4 3
#include "ShipManager.h"

ShipManager::ShipManager() {}

ShipManager::ShipManager(std::vector<ShipSize> sizes, std::vector<ShipOrientation> orientations) {
  for(auto size : sizes) {
    ships_.emplace_back(size);
  }
}

void ShipManager::AddShip(ShipSize size, ShipOrientation orientation) {
  ships_.emplace_back(size, orientation);
}

void ShipManager::RemoveShip(size_t ship_num) {
  ships_.erase(ships_.begin() - 1 + ship_num);
}

/*
void ShipManager::HitShip(size_t segment_number, size_t damage) {
  ships_[segment_number].segments_health_ - damage;
}
*/

std::vector<Ship>& ShipManager::get_ships_() {
  return ships_;
}

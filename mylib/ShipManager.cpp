#include "ShipManager.h"

ShipManager::ShipManager() = default;

ShipManager::ShipManager(const std::vector<std::pair<ShipSize, ShipOrientation>>& ships_data) {
  for(auto ship : ships_data) {
    ships_.emplace_back(ship.first, ship.second);
  }
}


void ShipManager::AddShip(const std::pair<ShipSize, ShipOrientation> ship_data) {
  ships_.emplace_back(ship_data.first, ship_data.second);
}

void ShipManager::RemoveShip(size_t ship_num) {
  ships_.erase(ships_.begin() - 1 + ship_num);
}

/*
std::vector<Ship>& ShipManager::get_ships_() {
  return ships_;
}
*/

size_t ShipManager::GerCountShips() {
  return ships_.size();
}
Ship& ShipManager::GetShip(size_t ship_num) {
  return ships_[ship_num];
}

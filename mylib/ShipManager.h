#ifndef LAB1_MYLIB_SHIPMANAGER_H_
#define LAB1_MYLIB_SHIPMANAGER_H_

#include <vector>

#include "Ship.h"
#include "HealthManager.h"

class ShipManager {
 public:
  ShipManager();
  explicit ShipManager(const std::vector<std::pair<ShipSize, ShipOrientation>>& ships_data);

  void AddShip(std::pair<ShipSize, ShipOrientation> ship_data);

  void RemoveShip(size_t ship_num);

  //std::vector<Ship>& get_ships_();
  Ship& GetShip(size_t ship_num);
  size_t GerCountShips();


 private:
  std::vector<Ship> ships_;


};

#endif

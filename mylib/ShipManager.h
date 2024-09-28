#ifndef LAB1_MYLIB_SHIPMANAGER_H_
#define LAB1_MYLIB_SHIPMANAGER_H_

#include <vector>

#include "Ship.h"
#include "HealthManager.h"

class ShipManager {
 public:
  ShipManager() = delete;
  ShipManager(std::vector<ShipSize> sizes, std::vector<ShipOrientation> orientations);

  void AddShip(ShipSize size, ShipOrientation orientation);

  void RemoveShip(size_t ship_num);

  std::vector<Ship>& get_ships_();

  // void HitShip(size_t ship_number, size_t segment_number, size_t damage);


 private:
  //size_t count_;
  std::vector<Ship> ships_;


};

#endif //LAB1_MYLIB_SHIPMANAGER_H_

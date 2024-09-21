#ifndef LAB1_MYLIB_SHIPMANAGER_H_
#define LAB1_MYLIB_SHIPMANAGER_H_

#include <vector>

#include "Ship.h"
#include "HealthManager.h"

class ShipManager {
 public:
  ShipManager() = delete;
  ShipManager(size_t count, std::vector<ShipSize> sizes);

  void AddShip(ShipSize size);

  void HitShip(size_t segment_number, size_t damage);


 private:
  size_t count_;
  std::vector<Ship> ships_;


};

#endif //LAB1_MYLIB_SHIPMANAGER_H_

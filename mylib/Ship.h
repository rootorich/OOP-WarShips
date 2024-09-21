#ifndef LAB1_MYLIB_SHIP_H_
#define LAB1_MYLIB_SHIP_H_

#include <vector>
#include "HealthManager.h"

enum class ShipSize {
  kTiny = 1,
  kSmall,
  kMedium,
  kHuge,
};

class Ship {
 public:
  Ship(ShipSize size = ShipSize::kTiny);

//  void set_health_(); // ?
//  void ChangeHealth();


 private:

  const ShipSize segments_;
  std::vector<HealthManager> segments_health_;


};

#endif //LAB1_MYLIB_SHIP_H_

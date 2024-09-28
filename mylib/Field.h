#ifndef LAB1_MYLIB_FIELD_H_
#define LAB1_MYLIB_FIELD_H_

#include <vector>


#include "Ship.h"
#include "HealthManager.h"

class Field {
 public:
  Field(size_t width = 8, size_t height = 8);


  bool PlaceShipToField(Ship& ship, size_t x, size_t y);

 private:
  bool CheckCollisionWithBorders(const ShipSize size, const ShipOrientation orientation, const size_t x, const size_t y);
  bool CheckCollisionWithShips(const ShipSize size, const ShipOrientation orientation, const size_t x, const size_t y);

  struct CellProperties {
    Ship* ship_p;
    size_t segment_num;
  };


  std::vector<std::vector<CellProperties>> cells_;


  size_t width_;
  size_t height_;

};

#endif

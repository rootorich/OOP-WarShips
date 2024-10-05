#ifndef LAB1_MYLIB_FIELD_H_
#define LAB1_MYLIB_FIELD_H_

#include <vector>


#include "Ship.h"
#include "HealthManager.h"

enum class CellStatus {
  kUnknown = 0,
  kEmpty = 1,
  kShip = 2,
  kInjured = 3,
  kDestroyed = 4,
};

class Field {
 public:
  Field(size_t width = 8, size_t height = 8);


  bool PlaceShipToField(Ship& ship, size_t x, size_t y);

  std::vector<std::vector<CellStatus>> get_cells_();

  void HideCells();
  void OpenCells();

 private:
  bool HasCollisionWithBorders(ShipSize size, ShipOrientation orientation, size_t x, size_t y) const;
  bool HasCollisionWithShips(ShipSize size, ShipOrientation orientation, size_t x, size_t y);

  struct CellProperties {
    Ship* ship_p;
    size_t segment_num;
    CellStatus status;
  };


  std::vector<std::vector<CellProperties>> cells_;


  size_t width_;
  size_t height_;

};

#endif

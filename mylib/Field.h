#ifndef LAB1_MYLIB_FIELD_H_
#define LAB1_MYLIB_FIELD_H_

#include <vector>

#include "Ship.h"
#include "HealthManager.h"
#include "ShipManager.h"

enum class CellStatus {
  kUnknown = 0,
  kEmpty = 1,
  kShip = 2,
  kInjured = 3,
  kDestroyed = 4,
};

class Field {
 public:
  Field(size_t width = 8, size_t height = 8, ShipManager& ship_manager);
  // ссылки использовать нельзя, из-за запрета копирования. Указатели возможно решат проблему

  Field(const Field& other);
  Field(Field&& other) noexcept;

  Field& operator = (const Field& other);
  Field& operator = (Field&& other) noexcept;

  bool PlaceShipToField(Ship& ship, size_t x, size_t y);

  std::vector<std::vector<CellStatus>> get_cells_();

  void HideCells();
  void OpenCells();

  CellStatus ConvertSegmentHealthToCellStatus(SegmentHealth health);
  void ChangeHealthCell(size_t x, size_t y, int value);


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

  ShipManager& ship_manager_;
};

#endif

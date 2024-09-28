#include "Field.h"

Field::Field(size_t width, size_t height) : width_{width}, height_{height} {
  cells_.resize(height, std::vector<CellProperties>(width, CellProperties{nullptr, 0}));
}

bool Field::CheckCollisionWithBorders(const ShipSize size, const ShipOrientation orientation, const size_t x, const size_t y) {
  if (orientation == ShipOrientation::kHorizontal) {
    if (x + static_cast<int>(size) > width_ || y + 1 > height_) {
      return false;
    }
  } else {
    if (x + 1 > width_ || y + static_cast<int>(size) > height_) {
      return false;
    }
  }

  return true;
}

bool Field::CheckCollisionWithShips(const ShipSize size, const ShipOrientation orientation, const size_t x, const size_t y) {
  std::pair <int, int> point_1 (x - 1, y - 1);
  std::pair <int, int> point_2;

  if (orientation == ShipOrientation::kHorizontal) {
    point_2 = std::make_pair(x + static_cast<int>(size), y + 1);
  } else {
    point_2 = std::make_pair(x + 1, y + static_cast<int>(size));
  }

  for (size_t i = 0; i < cells_.size(); ++i) {
    for (size_t j = 0; j < cells_[i].size(); ++j) {
      if (cells_[i][j].ship_p) {
        if (i >= point_1.second &&
            i <= point_2.second &&
            j >= point_1.first  &&
            j <= point_2.first) {
          return false;
        }
      }
    }
  }

  return true;
}

bool Field::PlaceShipToField(Ship& ship, size_t x, size_t y) {
  const ShipOrientation orientation = ship.get_orientation_();
  const ShipSize size = ship.get_segments_();

  if (CheckCollisionWithBorders(size, orientation, x, y)) {
    return false;
  }

  if (CheckCollisionWithShips(size, orientation, x, y)) {
    return false;
  }

  if (orientation == ShipOrientation::kHorizontal) {
    for (size_t i = 0; i < static_cast<int>(size); ++i) {
      cells_[y][x + i] = CellProperties{&ship, i};
    }
  } else {
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
      cells_[y + i][x] = CellProperties{&ship, i};
    }
  }

  return true;
}
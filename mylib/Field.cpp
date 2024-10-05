#include "Field.h"

Field::Field(size_t width, size_t height) : width_{width}, height_{height} {
  cells_.resize(height, std::vector<CellProperties>(width, CellProperties{nullptr, 0, CellStatus::kUnknown}));
}

bool Field::HasCollisionWithBorders(const ShipSize size, const ShipOrientation orientation, const size_t x, const size_t y) const {
  if (orientation == ShipOrientation::kHorizontal) {
    if (x + static_cast<int>(size) > width_ || y + 1 > height_) {
      return true;
    }
  } else {
    if (x + 1 > width_ || y + static_cast<int>(size) > height_) {
      return true;
    }
  }

  return false;
}

bool Field::HasCollisionWithShips(const ShipSize size, const ShipOrientation orientation, const size_t x, const size_t y) {
  std::pair <int, int> point_1 (x - 1, y - 1);
  std::pair <int, int> point_2;

  if (orientation == ShipOrientation::kHorizontal) {
    point_2 = std::make_pair(x + static_cast<int>(size), y + 1);
  } else {
    point_2 = std::make_pair(x + 1, y + static_cast<int>(size));
  }

  for (int i = 0; i < cells_.size(); ++i) {
    for (int j = 0; j < cells_[i].size(); ++j) {
      if (cells_[i][j].ship_p) {
        if (i >= point_1.second &&
            i <= point_2.second &&
            j >= point_1.first  &&
            j <= point_2.first) {
          return true;
        }
      }
    }
  }

  return false;
}

bool Field::PlaceShipToField(Ship& ship, size_t x, size_t y) {
  const ShipOrientation orientation = ship.get_orientation_();
  const ShipSize size = ship.get_segments_();

  if (HasCollisionWithBorders(size, orientation, x, y)) {
    return false;
  }

  if (HasCollisionWithShips(size, orientation, x, y)) {
    return false;
  }

  // FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX
  // CellStatus::kShip to CellStatus::kUnknown

  if (orientation == ShipOrientation::kHorizontal) {
    for (size_t i = 0; i < static_cast<int>(size); ++i) {
      cells_[y][x + i] = CellProperties{&ship, i, CellStatus::kShip};
    }
  } else {
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
      cells_[y + i][x] = CellProperties{&ship, i, CellStatus::kShip};
    }
  }
  // FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX FIX
  return true;
}

std::vector<std::vector<CellStatus>> Field::get_cells_() {
  std::vector<std::vector<CellStatus>> cells_status;

  for (size_t i = 0; i < cells_.size(); ++i) {
    cells_status.emplace_back();
    for (size_t j = 0; j < cells_[i].size(); ++j) {
      cells_status[i].emplace_back(cells_[i][j].status);
    }
  }

  return cells_status;
}

void Field::HideCells() {
  for (auto rows : cells_) {
    for (auto cell : rows) {
      cell.status = CellStatus::kUnknown;
    }
  }
}

void Field::OpenCells() {
  for (auto rows : cells_) {
    for (auto cell : rows) {
      if (cell.ship_p) {
        switch (cell.ship_p->get_segments_health_()[cell.segment_num].get_health_()) {
          case SegmentHealth::kUntouched:
            cell.status = CellStatus::kShip;
            break;
          case SegmentHealth::kInjured:
            cell.status = CellStatus::kInjured;
            break;

          case SegmentHealth::kDestroyed:
            cell.status = CellStatus::kDestroyed;
            break;
        }
      } else {
        cell.status = CellStatus::kEmpty;
      }
    }
  }
}

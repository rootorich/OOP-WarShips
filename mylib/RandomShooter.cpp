#include "RandomShooter.h"


RandomShooter::RandomShooter() {}

bool RandomShooter::Apply(Field& field, std::pair<size_t, size_t> coor) {
  return RandomShot(field);
}

bool RandomShooter::RandomShot(Field& field) {
  std::pair<size_t, size_t> coor;

  size_t hitable_cells = 0;

  auto cells = field.get_cells_();

  for (auto row : cells) {
    for (auto cell : row) {
      if (cell.status == CellStatus::kShip ||
          cell.status == CellStatus::kInjured) {

        ++hitable_cells;
      }
    }
  }

  size_t num_of_skip = std::rand() % (hitable_cells + 1);

  for (size_t i = 0; i < cells.size(); ++i) {
    for (size_t j = 0; j < cells[i].size(); ++j) {
      if (cells[i][j].status == CellStatus::kShip ||
          cells[i][j].status == CellStatus::kInjured) {

        if (num_of_skip == 0) {
          coor.first = i;
          coor.second = j;
          Shot(field, coor);
        } else {
          --num_of_skip;
        }
      }
    }
  }

  return false;
}
#include "Scanner.h"


bool Scanner::Apply(Field& field, std::pair<size_t, size_t> coor) {
  return Scan(field, coor);
}

bool Scanner::Scan(Field& field, std::pair<size_t, size_t> coor) {
  for (size_t i = coor.first; i < coor.first + 1; ++i) {
    for (size_t j = coor.second; j < coor.second + 1; ++j) {
      if (i <= field.get_cells_().size() &&
          j <= field.get_cells_()[i].size()) {

        if (field.get_cell_(i, j).status != CellStatus::kEmpty &&
            field.get_cell_(i, j).status != CellStatus::kNull) {
          return true;
        }
      }
    }
  }

  return false;
}

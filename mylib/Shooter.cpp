#include "Shooter.h"

Shooter::Shooter() : damage_{-1} {}

bool Shooter::Apply(Field& field, std::pair<size_t, size_t> coor) {
  return Shot(field, coor);
}

bool Shooter::Shot(Field& field, std::pair<size_t, size_t> coor) {
  if (field.get_cells_().size()    <= coor.first ||
      field.get_cells_()[0].size() <= coor.second) {
    throw std::runtime_error("Shot out of bounds");
  }
  
  if (field.get_cell_(coor.first, coor.second).status == CellStatus::kEmpty) {
    return false;
  } else {
    CellProperties cell = field.get_cell_(coor.first, coor.second);
    cell.ship_p->get_segments_health_()[cell.segment_num].set_health_(damage_);
  }

  return true;
}
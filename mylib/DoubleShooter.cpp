#include "DoubleShooter.h"

DoubleShooter::DoubleShooter() {
  damage_ = -2;
}

bool DoubleShooter::Apply(Field& field, std::pair<size_t, size_t> coor) {
  return DoubleShot(field, coor);
}

bool DoubleShooter::DoubleShot(Field& field, std::pair<size_t, size_t> coor) {
  return Shot(field, coor);
}
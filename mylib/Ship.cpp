#include "Ship.h"



Ship::Ship(ShipSize size) : segments_{size}
  {
    for(size_t i = 0; i < (int) size; i++) {
      //segments_health_.emplace_back(SegmentHealth::kUntouched);
    }
  }

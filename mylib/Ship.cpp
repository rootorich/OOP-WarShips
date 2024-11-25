#include "Ship.h"

Ship::Ship(ShipSize size, ShipOrientation orientation) : segments_{size}, orientation_{orientation}
{
  auto it_size = std::find(kSizeOrder.begin(), kSizeOrder.end(), size);

  for (auto it = kSizeOrder.begin(); it != it_size + 1; ++it) {
    segments_health_.emplace_back();
  }
}

std::array<ShipSize, 4> Ship::kSizeOrder = {ShipSize::kTiny, ShipSize::kSmall, ShipSize::kMedium, ShipSize::kHuge};

ShipSize Ship::get_size_() {
  return segments_;
}

ShipOrientation Ship::get_orientation_() {
  return orientation_;
}

std::vector<HealthManager>& Ship::get_segments_health_() {
  return segments_health_;
}


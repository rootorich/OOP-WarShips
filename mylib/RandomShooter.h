#include "Shooter.h"

#ifndef LAB1_RANDOMSHOOTER_H
#define LAB1_RANDOMSHOOTER_H

class RandomShooter : public Shooter {
 public:
  RandomShooter();

  bool Apply(Field& field, std::pair<size_t, size_t> coor) override;

  bool RandomShot(Field& field);
};

#endif

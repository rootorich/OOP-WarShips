#include "Field.h"

#ifndef LAB1_ABILITY_H
#define LAB1_ABILITY_H


class Ability {
 public:

  virtual bool Apply(Field& field, std::pair<size_t, size_t> coor);
};


#endif

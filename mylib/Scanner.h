#include "Ability.h"

#ifndef LAB1_SCANNER_H
#define LAB1_SCANNER_H


class Scanner : public Ability {
  bool Apply(Field& field, std::pair<size_t, size_t> coor) override;

  bool Scan(Field& field, std::pair<size_t, size_t> coor);
};


#endif

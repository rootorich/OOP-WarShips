#include <queue>
#include <map>
#include <memory>
#include <time.h>
#include <stdlib.h>
//#include <>

#include "Scanner.h"
#include "RandomShooter.h"
#include "DoubleShooter.h"

#ifndef LAB1_ABILITYMANAGER_H
#define LAB1_ABILITYMANAGER_H

enum class AbilityNames {
//  None = 0,
  Scanner = 0,
  RandomShooter = 1,
  DoubleShooter = 2,

  Last
};

class AbilityManager {
 public:
  AbilityManager();


  std::unique_ptr<Ability> GetAbility();

  void SetRandomAbility();

 private:
  std::queue<AbilityNames> queue_ability;
//  std::queue<std::unique_ptr<Ability>> queue_ability;

};

#endif

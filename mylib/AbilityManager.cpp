#include "AbilityManager.h"

AbilityManager::AbilityManager() {
  queue_ability;
}

std::unique_ptr<Ability> AbilityManager::GetAbility() {
  if (queue_ability.empty()) {
    throw std::runtime_error("Ability queue is empty!");
  }

  AbilityNames abilityName = queue_ability.front();
  queue_ability.pop();

  switch (abilityName) {
    case AbilityNames::Scanner:
      return std::make_unique<Scanner>();

    case AbilityNames::RandomShooter:
      return std::make_unique<RandomShooter>();

    case AbilityNames::DoubleShooter:
      return std::make_unique<DoubleShooter>();

    default:
      throw std::runtime_error("Unknown ability!");
  }
}

void AbilityManager::SetRandomAbility() {
  srand (time(0));

  int size = (int)AbilityNames::Last;
  int rand = std::rand() % size;

  queue_ability.push(static_cast<AbilityNames>(rand));
}
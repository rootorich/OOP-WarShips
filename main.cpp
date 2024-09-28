#include <iostream>

#include "mylib/IOManager.h"
#include "mylib/Ship.h"

int main() {



  ShipManager ship = ShipManager();

  std::cout << "Hello, World!" << std::endl;

  std::cout << (int)ship.get_segments_() << std::endl;

  //IOManager::GetInfoShip(ship);


  std::cout << "Hello, World!" << std::endl;

  return 0;
}

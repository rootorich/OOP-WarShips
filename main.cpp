#include <iostream>

#include "mylib/IOManager.h"
#include "mylib/ShipManager.h"

int main() {

  bool has_field = false;
  size_t user_command = 0;

  std::cout << "Start program!\n";

  ShipManager ship_manager = ShipManager();
  Field field;
  IOManager io_manager = IOManager();


  while (true) {
    std::cout << "Enter num of command:\n";
    std::cout << "1) Create Ship\n";
    std::cout << "2) Remove Ship\n";
    std::cout << "3) Change Ship\n";
    std::cout << "4) Get info Ships\n";
    if (has_field) {
      std::cout << "5) Place Ship\n";
    } else {
      std::cout << "5) Create Field\n";
    }

    std::cout << "0) Exit\n";

    std::cin >> user_command;

    switch (user_command) {
      case 1:
        io_manager.AddShip(ship_manager);
        break;

      case 2:
        io_manager.RemoveShip(ship_manager);
        break;

      case 3:
        io_manager.ChangeShip(ship_manager);
        break;

      case 4:
        io_manager.GetInfoShips(ship_manager);
        break;

      case 5:
        if (has_field) {
          io_manager.PlaceShip(field, ship_manager);
        } else {
          field = io_manager.CreateField();
        }
        break;

      case 0:
        std::cout << "End program\n";
        return 0;

      default:
        std::cout << "uncorrected input\n";
        break;
    }
  }





  return 0;
}

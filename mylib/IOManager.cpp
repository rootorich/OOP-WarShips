#include <iostream>
#include "IOManager.h"



IOManager::IOManager() {}

void IOManager::GetInfoShip(Ship shiper) {
  std::cout << "count segments = " << static_cast<int>(shiper.get_segments_())   << "\n";
}

void IOManager::GetInfoShips(ShipManager ship_manager) {
  std::vector<Ship> ships = ship_manager.get_ships_();

  for (size_t i = 0; i < ships.size(); ++i) {
    std::cout << i + 1 << ") ";

    std::cout << "size = ";

    switch (ships[i].get_segments_()) {
      case ShipSize::kTiny:
        std::cout << 1;
        break;

      case ShipSize::kSmall:
        std::cout << 2;
        break;

      case ShipSize::kMedium:
        std::cout << 3;
        break;

      case ShipSize::kHuge:
        std::cout << 4;
        break;

      default:
        std::cout << "unknown error";
    }

    std::cout << " orientation = ";

    switch (ships[i].get_orientation_()) {
      case ShipOrientation::kHorizontal:
        std::cout << "horizontal";
        break;

      case ShipOrientation::kVertical:
        std::cout << "vertical";
        break;

      default:
        std::cout << "unknown error";
    }

    std::cout << "\n";
  }
}
void IOManager::RemoveShip(ShipManager ship_manager, size_t ship_num) {
  ship_manager.RemoveShip(ship_num - 1);
}

void IOManager::AddShip(ShipManager ship_manager) {
  size_t player_size;
  std::string player_orientation;
  ShipSize size;
  ShipOrientation orientation;

  while (true) {
    std::cout << "Enter size (from 1 to 4) (default = 1): ";
    std::cin >> player_size;
    if (player_size >= 1 && player_size <= 4) {
      size = ShipSize(player_size);
      break;
    } else {
      std::cout << "uncorrected size";
    }
  }

  while (true) {
    std::cout << "Enter orientation (horizontal (0) or vertical (1)) (default = horizontal): ";
    std::cin >> player_orientation;
    if (player_orientation == "horizontal" || player_orientation == "0") {
      orientation = ShipOrientation::kHorizontal;
      break;
    } else if (player_orientation == "vertical" || player_orientation == "1") {
      orientation = ShipOrientation::kVertical;
      break;
    } else {
      std::cout << "uncorrected orientation\n";
    }
  }

  ship_manager.AddShip(size, orientation);
}

Field IOManager::CreateField() {
  int width;
  int height;

  while (true) {
    std::cout << "Enter sizes field (default width = 8 and height = 8) (not greater than 50): ";
    std::cin >> width >> height;

    if (width < 0 || height < 0) {
      std::cout << "width and height should be greater than 0\n";
    } else if (width > 50 || height > 50) {
      std::cout << "width and height should be not greater than 50\n";
    } else {
      std::cout << "Set width = " << width << " and height = " << height;
      break;
    }
  }

  return Field(width, height);
}

void IOManager::PlaceShip(Field field, ShipManager ship_manager, size_t ship_num) {
  int x;
  int y;
  Ship& ship = ship_manager.get_ships_()[ship_num];

  while (true) {
    std::cout << "Enter left-top position ship (coord x and y): ";
    std::cin >> x >> y;
    
    if (x < 0 || y < 0) {
      std::cout << "uncorrected position\n";
    } else {
      if (field.PlaceShipToField(ship, x, y)) {
        std::cout << "Ship is placed\n";
        break;
      } else {
        std::cout << "uncorrected position\n";
      }
    }
  }
}

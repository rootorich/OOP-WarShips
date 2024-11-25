#include <iostream>
#include "IOManager.h"



IOManager::IOManager() {}

void IOManager::GetInfoShip(Ship shiper) {
  std::cout << "count segments = " << static_cast<int>(shiper.get_segments_())   << "\n";
}

void IOManager::GetInfoShips(ShipManager& ship_manager) {
  std::vector<Ship> ships = ship_manager.get_ships_();

  if (ships.empty()) {
    std::cout << "I don't have ships\n";
  } else {
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
  std::cout << "\n";
}
void IOManager::RemoveShip(ShipManager& ship_manager) {
  size_t ship_num = IOManager::GetShip(ship_manager);

  if (ship_manager.get_ships_().empty()) {
    std::cout << "I don't have ships";
  } else {
    ship_manager.RemoveShip(ship_num - 1);
  }
}

void IOManager::AddShip(ShipManager& ship_manager) {
  size_t player_size;
  std::string player_orientation;
  ShipSize size;
  ShipOrientation orientation;

  while (true) {
    std::cout << "Enter size (from 1 to 4): ";
    std::cin >> player_size;
    if (player_size >= 1 && player_size <= 4) {
      size = ShipSize(player_size);
      break;
    } else {
      std::cout << "uncorrected size\n";
    }
  }

  while (true) {
    std::cout << "Enter orientation (horizontal (0) or vertical (1)): ";
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

  std::cout << "\n";

  ship_manager.AddShip(size, orientation);
}

void IOManager::ChangeShip(ShipManager& ship_manager) {
  IOManager::RemoveShip(ship_manager);
  IOManager::AddShip(ship_manager);
}

Field IOManager::CreateField() {
  int width;
  int height;

  while (true) {
    std::cout << "Enter width and height sizes field (less than 50x50): ";
    std::cin >> width >> height;

    if (width < 0 || height < 0) {
      std::cout << "width and height should be greater than 0\n";
    } else if (width > 50 || height > 50) {
      std::cout << "width and height should be not greater than 50\n";
    } else {
      std::cout << "Set width = " << width << " and height = " << height << "\n\n";
      break;
    }
  }

  return Field(width, height);
}

void IOManager::PlaceShip(Field& field, ShipManager& ship_manager) {
  size_t ship_num = IOManager::GetShip(ship_manager);

  int x;
  int y;
  Ship& ship = ship_manager.get_ships_()[ship_num];

  while (true) {
    std::cout << "Enter left-top position ship (coord x and y): ";
    std::cin >> x >> y;
    
    if (x < 1 || y < 1) {
      std::cout << "uncorrected position\n";
      std::cout << "inputs less 1\n";
    } else {
      if (field.PlaceShipToField(ship, x - 1, y - 1)) {
        std::cout << "Ship is placed\n\n";
        break;
      } else {
        std::cout << "uncorrected position\n";
      }
    }
  }
}

size_t IOManager::GetShip(ShipManager& ship_manager) {
  size_t ship_num;

  while (true) {
    std::cout << "Enter num of ship: ";

    std::cin >> ship_num;

    if (ship_num > 0 && ship_num <= ship_manager.get_ships_().size()) {
      break;
    } else {
      std::cout << "uncorrected num of ship\n";
    }
  }

  return ship_num - 1;
}

void IOManager::ShowField(Field& field) {
  std::vector<std::vector<CellProperties>> cells_status = field.get_cells_();

  for (const auto& rows : cells_status) {
    std::cout << "    ";
    for (auto cell : rows) {
      std::cout << " ";

      if (!cell.vision) {
        std::cout << "?";
      } else {
        switch (cell.status) {
          case CellStatus::kEmpty:
            std::cout << "0";
            break;

          case CellStatus::kShip:
            std::cout << "#";
            break;

          case CellStatus::kInjured:
            std::cout << "*";
            break;

          case CellStatus::kDestroyed:
            std::cout << "X";
            break;

          default:
            std::cout << "W";
            break;

        }
      }

    }

    std::cout << "\n";
  }

  std::cout << "\n";
}

void IOManager::HideField(Field& field) {
  field.HideCells();

  std::cout << "Field is closed\n\n";
}

void IOManager::OpenField(Field& field) {
  field.OpenCells();

  std::cout << "Field is opened\n\n";
}

void IOManager::HitCell(Field& field) {
  int damage_value;

  while (true) {
    std::cout << "Enter damage value (>= 0): ";

    std::cin >> damage_value;

    if (damage_value >= 0) {
      break;
    } else {
      std::cout << "uncorrected value (less 0)\n";
    }
  }
  std::cout << "damage = " << damage_value << "\n";

  IOManager::ChangeHealthCell(field, -damage_value);
}

void IOManager::HealCell(Field& field) {
  int heal_value;

  while (true) {
    std::cout << "Enter heal value (>= 0): ";

    std::cin >> heal_value;

    if (heal_value >= 0) {
      break;
    } else {
      std::cout << "uncorrected value (less 0)\n";
    }
  }
  std::cout << "heal = " << heal_value << "\n";

  IOManager::ChangeHealthCell(field, heal_value);
}

void IOManager::ChangeHealthCell(Field& field, int value) {
  int x, y;
  size_t height = field.get_cells_().size();
  size_t width = field.get_cells_()[0].size();

  while (true) {
    std::cout << "Enter cell's coordinates (coord x and y): ";
    std::cin >> y >> x;

    if (x < 1 || y < 1 || x > width || y > height) {
      std::cout << "uncorrected position\n";
      std::cout << "inputs less 1 or greater " << width << " or " << height << "\n";
    } else {
      field.ChangeHealthCell(x - 1, y - 1, value);
      break;
    }
  }
}

void IOManager::UseAbility(Field& field, AbilityManager& abilityManager) {
  int x, y;
  std::unique_ptr<Ability> ability;

  try {
    ability = abilityManager.GetAbility();
  }
  catch (const std::string& error) {
    std::cout << error << "\n";
  }

  while (true) {
    std::cout << "Enter cell's coordinates (coord x and y): ";
    std::cin >> y >> x;

    try {
      ability->Apply(field, std::pair<int, int>(x,y));
    }
    catch (const std::string& error) {
      std::cout << error << "\n";
      continue;
    }

    if (!field.is_live(x, y)) {
      abilityManager.SetRandomAbility();
    }

    break;
  }
}

void IOManager::QuickStartShip(Field& field, ShipManager& ship_manager) {
  ship_manager.AddShip(ShipSize::kHuge, ShipOrientation::kHorizontal);
  ship_manager.AddShip(ShipSize::kHuge, ShipOrientation::kVertical);
  ship_manager.AddShip(ShipSize::kMedium, ShipOrientation::kHorizontal);
  ship_manager.AddShip(ShipSize::kMedium, ShipOrientation::kVertical);
  ship_manager.AddShip(ShipSize::kSmall, ShipOrientation::kHorizontal);
  ship_manager.AddShip(ShipSize::kSmall, ShipOrientation::kVertical);
  ship_manager.AddShip(ShipSize::kTiny, ShipOrientation::kHorizontal);
  ship_manager.AddShip(ShipSize::kTiny, ShipOrientation::kVertical);
}

void IOManager::QuickStartField(Field& field, ShipManager& ship_manager) {
  field = Field(8, 8);
}

void IOManager::QuickStartPlace(Field& field, ShipManager& ship_manager) {
  field.PlaceShipToField(ship_manager.get_ships_()[0], 0, 0);
  field.PlaceShipToField(ship_manager.get_ships_()[1], 0, 2);
  field.PlaceShipToField(ship_manager.get_ships_()[2], 2, 2);
  field.PlaceShipToField(ship_manager.get_ships_()[3], 4, 4);
  field.PlaceShipToField(ship_manager.get_ships_()[6], 6, 6);
  field.PlaceShipToField(ship_manager.get_ships_()[7], 7, 0);
}

void IOManager::QuickStart(Field& field, ShipManager& ship_manager) {
  IOManager::QuickStartShip(field, ship_manager);
  IOManager::QuickStartField(field, ship_manager);
  IOManager::QuickStartPlace(field, ship_manager);
}






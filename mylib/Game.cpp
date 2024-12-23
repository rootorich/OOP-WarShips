#include "Game.h"

Game::Game() {
  io_manager_ = IOManager();

  game_is_start_ = false;
  stage_ = 1;

  std::cout << "Start Game!\n";

  MainMenu();

}

void Game::Process() {

  size_t user_command = 0;

  while (true) {
    std::cout << "\nAvailable options:\n\n";

    std::cout << "1) Shot\n";
    std::cout << "2) Use Ability\n";
    std::cout << "3) Ability List\n";


    std::cout << "Enter num of command:";
    std::cin >> user_command;


    break;

  }
}

void Game::MainMenu() {
  size_t user_command = 0;

  std::cout << "\nAvailable options:\n\n";

  std::cout << "1. New Game\n";
  std::cout << "2. Load Game\n";
  std::cout << "Any other. Exit Game\n";

  std::cout << "Enter num of command:";
  std::cin >> user_command;

  switch (user_command) {
    case 1:
      NewGame();
      break;
    case 2:
      Load();
      break;

    default:
      ExitGame();
      break;
  }
}

void Game::ExitGame() {
  if (game_is_start_) {
    size_t user_command = 0;

    std::cout << "Save Game?\n";
    std::cout << "1. Yes\n";
    std::cout << "Any other. No\n";

    std::cout << "Enter num of command:";
    std::cin >> user_command;

    switch(user_command) {
      case 1:
        Save();
        break;

      default:
        exit(1);
        break;

    }
  }
}

void Game::Save() {
    Saver saver("file.txt");
    auto field0 = players_[0].get_field_();
    auto field1 = players_[1].get_field_();

    SaveField(saver, field0);
    SaveField(saver, field1);
}

void Game::Load() {
    Saver saver("file.txt");

    Field* field0 = LoadField(saver);
    Field* field1 = LoadField(saver);



    game_is_start_ = true;
    Process();
}


void Game::SaveField(Saver& saver, Field& field){
    std::vector<std::vector<CellProperties>> cells = field.get_cells_();

    std::map<Ship*, size_t> map;
    std::vector<Ship*> ships;

    for (auto & cell : cells){
        for (auto & item : cell){
            if (item.segment_num == 0){
                map[item.ship_p] = ships.size();
                ships.push_back(item.ship_p);
            }
        }
    }

    saver.saveData(ships.size());

    for (auto & ship : ships){
        SaveShip(saver, *ship);
    }

    saver.saveData(cells.size());
    saver.saveData(cells[0].size());

    for (int i = 0; i < cells.size(); ++i){
        for (int j = 0; j < cells[i].size(); ++j){
            SavedCellProperties savedCellProperties{};
            savedCellProperties.ship_number = map[cells[i][j].ship_p];
            savedCellProperties.segment_num = cells[i][j].segment_num;
            savedCellProperties.status = cells[i][j].status;
            savedCellProperties.vision = cells[i][j].vision;

            SaveCellProperties(saver, savedCellProperties);
        }
    }
}

void Game::CreatePlayer() {

    Player player();
}

Field* Game::LoadField(Saver& saver) {
    int ships_size = saver.loadData<int>();

    std::vector<Ship*> ships;

    for (int i = 0; i < ships_size; ++i){
        ships.push_back(LoadShip(saver));
    }

    int rows = saver.loadData<int>();
    int colls = saver.loadData<int>();

    auto field = new Field();

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < colls; ++j){
            SavedCellProperties savedCellProperties = LoadCellProperties(saver);

            CellProperties cellProperties = {};
            cellProperties.ship_p = ships[savedCellProperties.ship_number];
            cellProperties.segment_num = savedCellProperties.segment_num;
            cellProperties.vision = savedCellProperties.vision;
            cellProperties.status = savedCellProperties.status;

            field->SetCell(i, j, cellProperties);
        }
    }

    return field;
}

void Game::SaveShip(Saver& saver, Ship ship) {

    ShipSize ship_size = ship.get_segments_();
    ShipOrientation ship_orientation = ship.get_orientation_();

    saver.saveData((int)ship_size);
    saver.saveData((int)ship_orientation);
}

Ship* Game::LoadShip(Saver& saver) {
    auto ship_size = (ShipSize)saver.loadData<int>();
    auto ship_orientation = (ShipOrientation)saver.loadData<int>();

    Ship* ship = new Ship(ship_size, ship_orientation);

    return ship;
}

void Game::SaveCellProperties(Saver& saver, SavedCellProperties savedCellProperties) {
    saver.saveData((int)savedCellProperties.ship_number);
    saver.saveData(savedCellProperties.segment_num);
    saver.saveData((int)savedCellProperties.status);
    saver.saveData(savedCellProperties.vision);
}

SavedCellProperties Game::LoadCellProperties(Saver& saver) {
    SavedCellProperties savedCellProperties{};
    savedCellProperties.ship_number = saver.loadData<int>();
    savedCellProperties.segment_num = saver.loadData<int>();
    savedCellProperties.status = (CellStatus)saver.loadData<int>();
    savedCellProperties.vision = saver.loadData<bool>();

    return savedCellProperties;
}

void Game::CreateShips(ShipManager& ship_manager) {
  bool is_exit = false;
  size_t user_command = 0;

  while (true) {
    std::cout << "\nCreate Ship:\n\n";


    std::cout << "1. Add Ship\n";
    std::cout << "2. Remove Ship\n";
    std::cout << "3. Place Ship\n";

    std::cout << "0. Finish Creation\n";


    std::cout << "Enter num of command:";
    std::cin >> user_command;

    switch (user_command) {
      case 1:
        io_manager_.AddShip(ship_manager);
        break;
      case 2:
        io_manager_.AddShip(ship_manager);
        break;
      case 3:
        io_manager_.AddShip(ship_manager);
        break;
      case 0:
        is_exit = true;
        break;

      default:
        std::cout << "unknown command\n";
        break;
    }

    if (is_exit) {
      break;
    }
  }
}

void Game::CreateBot(Field field, ShipManager ship_manager){
}

void Game::NewGame() {
  CreatePlayer();

  Field field = io_manager_.CreateField();
  players_[0].set_field_(field);

  ShipManager ship_manager = ShipManager();
  CreateShips(ship_manager);

  CreateBot(field, ship_manager);


  Process();
}




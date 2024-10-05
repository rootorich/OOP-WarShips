#ifndef LAB1_IOMANAGER_H
#define LAB1_IOMANAGER_H

#include "ShipManager.h"
#include "Field.h"


class IOManager {
 public:
  IOManager();


  static void GetInfoShip(Ship ship);

  void GetInfoShips(ShipManager& ship_manager);

  void RemoveShip(ShipManager& ship_manager);
  void AddShip(ShipManager& ship_manager);
  void ChangeShip(ShipManager& ship_manager);

  Field CreateField();

  void PlaceShip(Field& field, ShipManager& ship_manager);

 private:
  size_t GetShip(ShipManager& ship_manager);

};


#endif //LAB1_IOMANAGER_H

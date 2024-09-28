#ifndef LAB1_IOMANAGER_H
#define LAB1_IOMANAGER_H

#include "ShipManager.h"
#include "Field.h"


class IOManager {
 public:
  IOManager();

  static void GetInfoShip(Ship ship);

  void GetInfoShips(ShipManager ship_manager);

  void RemoveShip(ShipManager ship_manager, size_t ship_num);
  void AddShip(ShipManager ship_manager);
  void ChangeShip(size_t ship_num);

  Field CreateField();

  void PlaceShip(Field field, ShipManager ship_manager, size_t ship_num);

 private:
};


#endif //LAB1_IOMANAGER_H

#include <iostream>
#include "IOManager.h"



IOManager::IOManager() {}

void IOManager::GetInfoShip(Ship shiper) {
  std::cout << "count segments = " << static_cast<int>(shiper.get_segments_())   << "\n";
}
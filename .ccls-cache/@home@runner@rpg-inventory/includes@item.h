#ifndef RPG_ITEM_H
#define RPG_ITEM_H

#include "slot.h"
#include <iostream>

struct Item {
  int id;
  std::string name;
  int worth;
  float weight;
  Slot slot;
};

#endif // RPG_ITEM_H
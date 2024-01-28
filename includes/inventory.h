#ifndef RPG_INVENTORY_H
#define RPG_INVENTORY_H

#include <algorithm>
#include <iostream>
#include <vector>

#include "item.h"

class Inventory {
private:
  std::vector<Item> items;

public:
  void addItem(const Item &newItem);
  void sortItemsByWorth();
  void sortItemsByWeight();
  void displayInventory();

  const std::vector<Item> &getItems();
  Item *findItemById(int id);
};

#endif // RPG_INVENTORY_H

#ifndef RPG_INVENTORY_H
#define RPG_INVENTORY_H

#include <algorithm>
#include <iostream>
#include <vector>

#include "rarity.h"

struct Item {
  int id;
  std::string name;
  int worth;
  float weight;
  Rarity rarity;
};

class Inventory {
private:
  std::vector<Item> items;

public:
  void addItem(const Item &newItem);
  void removeItem(int itemId);
  void sortItemsByWorth();
  void sortItemsByWeight();
  void sortItemsByRarity();
  void displayInventory();
};

#endif // RPG_INVENTORY_H

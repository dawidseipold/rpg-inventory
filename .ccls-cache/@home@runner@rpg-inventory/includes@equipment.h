#ifndef RPG_EQUIPMENT_H
#define RPG_EQUIPMENT_H

#include "inventory.h"
#include <unordered_map>

enum class Slot { Weapon, Armor, Gloves, Helmet, Boots };

class Equipment {
private:
  std::unordered_map<Slot, Item> equippedItems;

public:
  void equipItem(Slot slot, Item &newItem);
  void unequipItem(Slot slot);
  void displayEquipment();
};

#endif // RPG_EQUIPMENT_H
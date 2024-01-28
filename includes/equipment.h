#ifndef RPG_EQUIPMENT_H
#define RPG_EQUIPMENT_H

#include "item.h"
#include "slot.h"

#include <unordered_map>

class Equipment {
private:
  std::unordered_map<Slot, Item> equippedItems;

public:
  void equipItem(Slot slot, Item &newItem);
  void unequipItem(Slot slot);
  const std::unordered_map<Slot, Item> &getEquippedItems() const;
};

#endif // RPG_EQUIPMENT_H
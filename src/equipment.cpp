#include "../includes/equipment.h"

void Equipment::equipItem(Slot slot, Item &newItem) {
  equippedItems[slot] = newItem;
}

void Equipment::unequipItem(Slot slot) { equippedItems.erase(slot); }

const std::unordered_map<Slot, Item> &Equipment::getEquippedItems() const {
  return equippedItems;
}

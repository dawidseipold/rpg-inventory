#include "../includes/equipment.h"

void Equipment::equipItem(Slot slot, Item &newItem) {
  equippedItems[slot] = newItem;
}

void Equipment::unequipItem(Slot slot) { equippedItems.erase(slot); }

void Equipment::displayEquipment() {
  for (auto &item : equippedItems) {
    std::cout << static_cast<int>(item.first) << item.second.name << std::endl;
  }
}
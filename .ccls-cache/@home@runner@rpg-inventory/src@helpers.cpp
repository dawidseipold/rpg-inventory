#include "../includes/slot.h"

int generateID(int &previousID) { return ++previousID; };

Slot generateSlot(int slotID) {
  switch (slotID) {
  case 1:
    return Slot::Weapon;
  case 2:
    return Slot::Armor;
  case 3:
    return Slot::Gloves;
  case 4:
    return Slot::Helmet;
  case 5:
    return Slot::Boots;
  default:
    return Slot::Invalid;
  }
}
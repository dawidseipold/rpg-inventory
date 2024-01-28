#include <iostream>
#include <limits>
#include <utility>

#include "includes/equipment.h"
#include "includes/inventory.h"
#include "includes/slot.h"

int generateID(int &previousID) { return ++previousID; };

// TODO: Instead of slotID make it to provide enum value
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

int main() {
  Inventory playerInventory;
  Equipment playerEquipment;

  int previousID = 0;

  while (true) {
    std::cout << "\n------ RPG Inventory Simulation ------\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. Display Inventory\n";
    std::cout << "3. Sort by Worth\n";
    std::cout << "4. Sort by Weight\n";
    std::cout << "5. Equip an Item\n";
    std::cout << "6. Unequip an Item\n";
    std::cout << "7. Display equipped Items\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    // Check for invalid input
    if (std::cin.fail()) {
      std::cin.clear();

      // Discard invalid input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    }

    switch (choice) {
    case 1: {
      std::string name;
      int worth;
      float weight;
      int slotID;

      std::cout << "Enter item name:";
      // TODO: Fix this - The space is passed into the next line
      std::cin >> std::ws;
      std::getline(std::cin, name);

      std::cout << "Enter item worth:";
      std::cin >> worth;

      std::cout << "Enter item weight:";
      std::cin >> weight;

      // TODO: Add a check for invalid input
      std::cout << "Enter item slot (1: Weapon, 2: Armor, 3: "
                   "Gloves, 4: Helmet, 5: Boots):";
      std::cin >> slotID;

      Item newItem{generateID(previousID), name, worth, weight,
                   generateSlot(slotID)};
      playerInventory.addItem(newItem);

      break;
    }

    case 2: {
      std::cout << "\nCurrent Inventory:\n";
      playerInventory.displayInventory();

      break;
    }

    case 3: {
      std::cout << "\nSorting by worth:\n";
      playerInventory.sortItemsByWorth();
      playerInventory.displayInventory();

      break;
    }

    case 4: {
      std::cout << "\nSorting by weight:\n";
      playerInventory.sortItemsByWeight();
      playerInventory.displayInventory();

      break;
    }

      // TODO: Display equipped items before selecting a slot and after
      // equipping an item
      // TODO: Display unequipped items on a certain slot and replace the
      // previously equipped item with a selected one
    case 5: {
      int slot;
      std::cout << "Select a slot to equip an item (1: Weapon, 2: Armor, 3: "
                   "Gloves, 4: Helmet, 5: Boots): ";
      std::cin >> slot;

      std::vector<Item> availableItems;
      for (auto &item : playerInventory.getItems()) {
        if (item.slot == static_cast<Slot>(slot) &&
            playerEquipment.getEquippedItems().count(item.slot) == 0) {
          availableItems.push_back(item);
        }
      }

      std::cout << "Available items to equip in slot " << slot << ": "
                << std::endl;
      for (const auto &item : availableItems) {
        std::cout << "ID: " << item.id << " - " << item.name << std::endl;
      }

      int equipItemId;
      std::cout << "Enter the ID of the item to equip: ";
      std::cin >> equipItemId;

      Item *itemToEquip = playerInventory.findItemById(equipItemId);
      if (itemToEquip != nullptr &&
          itemToEquip->slot == static_cast<Slot>(slot)) {
        playerEquipment.equipItem(static_cast<Slot>(slot), *itemToEquip);
        std::cout << "Item equipped successfully." << std::endl;
      } else {
        std::cout
            << "Invalid item ID or item category does not match selected slot."
            << std::endl;
      }

      break;
    }

      // TODO: Display equipped items before selecting a slot and after
      // unequipping an item
    case 6: {
      int slot;
      std::cout << "Select a slot to unequip (1: Weapon, 2: Armor, 3: "
                   "Gloves, 4: Helmet, 5: Boots): ";
      std::cin >> slot;

      playerEquipment.unequipItem(generateSlot(slot));

      std::cout << "Item unequipped successfully." << std::endl;

      break;
    }

    case 7: {
      std::cout << "\nCurrent Equipment:\n";
      playerEquipment.getEquippedItems();

      break;
    }

    case 0:
      std::cout << "Exiting program.\n";

      return 0;

    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  }
}
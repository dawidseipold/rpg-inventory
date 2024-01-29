#include <iostream>
#include <limits>

#include "includes/getValidInput.h"
#include "includes/inventory.h"
#include "includes/rarityConverter.h"

int generateID(int &previousID) { return ++previousID; };

int main() {
  Inventory playerInventory;

  int previousID = 0;

  while (true) {
    std::cout << "\n------ RPG Inventory Simulation ------\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. Remove Item\n";
    std::cout << "3. Display Inventory\n";
    std::cout << "4. Sort by Worth\n";
    std::cout << "5. Sort by Weight\n";
    std::cout << "6. Sort by Rarity\n";
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
      std::string name = getValidInput<std::string>("Enter item name: ");
      int worth = getValidInput<int>("Enter item worth: ");
      float weight = getValidInput<float>("Enter item weight: ");
      int rarity = getValidInput<int>(
          "Enter item rarity (1. Common, 2. Uncommon, 3. Rare, 4. "
          "Epic, 5. Legendary, 6. Mythic): ");

      Item newItem{generateID(previousID), name, worth, weight,
                   numberToRarity(rarity)};
      playerInventory.addItem(newItem);

      break;
    }

    case 2: {
      int id;

      std::cout << "\nPick an ID of an item you want to remove:\n";
      std::cin >> id;

      playerInventory.removeItem(id);

      break;
    }

    case 3: {
      std::cout << "\nCurrent Inventory:\n";
      playerInventory.displayInventory();

      break;
    }

    case 4: {
      std::cout << "\nSorting by worth:\n";
      playerInventory.sortItemsByWorth();
      playerInventory.displayInventory();

      break;
    }

    case 5: {
      std::cout << "\nSorting by weight:\n";
      playerInventory.sortItemsByWeight();
      playerInventory.displayInventory();

      break;
    }

    case 6: {
      std::cout << "\nSorting by rarity:\n";
      playerInventory.sortItemsByRarity();
      playerInventory.displayInventory();

      break;
    }

    case 0: {
      std::cout << "Exiting program.\n";

      return 0;
    }

    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  }
}
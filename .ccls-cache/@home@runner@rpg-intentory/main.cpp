#include <iostream>
#include <limits>

#include "includes/inventory.h"
// #include "includes/equipment.h"

int generateID(int &previousID) { return ++previousID; };

int main() {
  Inventory playerInventory;
  // Equipment playerEquipment;

  int previousID = 0;

  while (true) {
    std::cout << "\n------ RPG Inventory Simulation ------\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. Display Inventory\n";
    std::cout << "3. Sort by Worth\n";
    std::cout << "4. Sort by Weight\n";
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

      std::cout << "Enter item name:";
      // TODO: Fix this - The space is passed into the next line
      std::cin >> std::ws;
      std::getline(std::cin, name);

      std::cout << "Enter item worth:";
      std::cin >> worth;

      std::cout << "Enter item weight:";
      std::cin >> weight;

      Item newItem{generateID(previousID), name, worth, weight};
      playerInventory.addItem(newItem);

      break;
    }

    case 2:
      std::cout << "\nCurrent Inventory:\n";
      playerInventory.displayInventory();

      break;

    case 3:
      std::cout << "\nSorting by worth:\n";
      playerInventory.sortItemsByWorth();
      playerInventory.displayInventory();

      break;

    case 4:
      std::cout << "\nSorting by weight:\n";
      playerInventory.sortItemsByWeight();
      playerInventory.displayInventory();

      break;

    case 0:
      std::cout << "Exiting program.\n";

      return 0;

    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  }
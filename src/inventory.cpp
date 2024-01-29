#include <algorithm>
#include <iostream>

#include "../includes/inventory.h"
#include "../includes/rarityConverter.h"

void Inventory::addItem(const Item &newItem) { items.push_back(newItem); }

void Inventory::removeItem(int itemId) {
  items.erase(
      std::remove_if(items.begin(), items.end(),
                     [itemId](const Item &item) { return item.id == itemId; }),
      items.end());
}

void Inventory::sortItemsByWorth() {
  std::sort(items.begin(), items.end(),
            [](const Item &a, const Item &b) { return a.worth > b.worth; });
};

void Inventory::sortItemsByWeight() {
  std::sort(items.begin(), items.end(),
            [](const Item &a, const Item &b) { return a.weight > b.weight; });
};

void Inventory::sortItemsByRarity() {
  std::sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
    return rarityToNumber(a.rarity) > rarityToNumber(b.rarity);
  });
}

void Inventory::displayInventory() {
  if (items.size() > 0) {
    for (const auto &item : items) {
      std::cout << "ID: " << item.id << "\n";
      std::cout << "Name: " << item.name << "\n";
      std::cout << "Worth: " << item.worth << "\n";
      std::cout << "Weight: " << item.weight << "\n";
      std::cout << "Rarity: " << rarityToString(item.rarity) << "\n";
    }
  }

  else {
    std::cout << "Inventory is empty.\n";
  }
}
#include <algorithm>
#include <iostream>
#include <map>

#include "../includes/inventory.h"
#include "./helpers.cpp"

// Helper functions
std::map<Slot, std::string> slotToString = {{Slot::Weapon, "Weapon"},
                                            {Slot::Armor, "Armor"},
                                            {Slot::Helmet, "Helmet"},
                                            {Slot::Gloves, "Gloves"},
                                            {Slot::Boots, "Boots"}};

// Class public functions
void Inventory::addItem(const Item &newItem) { items.push_back(newItem); }

void Inventory::sortItemsByWorth() {
  std::sort(items.begin(), items.end(),
            [](const Item &a, const Item &b) { return a.worth > b.worth; });
};

void Inventory::sortItemsByWeight() {
  std::sort(items.begin(), items.end(),
            [](const Item &a, const Item &b) { return a.weight > b.weight; });
};

void Inventory::displayInventory() {
  for (const auto &item : items) {
    std::cout << "ID: " << item.id << "\n";
    std::cout << "Name: " << item.name << "\n";
    std::cout << "Worth: " << item.worth << "\n";
    std::cout << "Weight: " << item.weight << "\n";
    std::cout << "Slot: " << slotToString[item.slot] << "\n";
  }
}

const std::vector<Item> &Inventory::getItems() { return items; }

Item *Inventory::findItemById(int id) {
  for (auto &item : items) {
    if (item.id == id) {
      return &item;
    }
  }

  return nullptr;
}

// Case functions

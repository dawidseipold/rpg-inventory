#include <algorithm>
#include <iostream>

#include "../includes/inventory.h"

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
    }
}
#ifndef RPG_INVENTORY_H
#define RPG_INVENTORY_H

#include <algorithm>
#include <iostream>
#include <vector>

struct Item {
    int id;
    std::string name;
    int worth;
    float weight;
};

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item &newItem);
    void sortItemsByWorth();
    void sortItemsByWeight();
    void displayInventory();
};

#endif // RPG_INVENTORY_H

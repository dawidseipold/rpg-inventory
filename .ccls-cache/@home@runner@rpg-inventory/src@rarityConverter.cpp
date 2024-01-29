#include "../includes/rarityConverter.h"
#include <iostream>

static const std::map<std::string, std::pair<Rarity, int>> rarityMap = {
    {"Common", {Rarity::Common, 1}},       {"Uncommon", {Rarity::Uncommon, 2}},
    {"Rare", {Rarity::Rare, 3}},           {"Epic", {Rarity::Epic, 4}},
    {"Legendary", {Rarity::Legendary, 5}}, {"Mythic", {Rarity::Mythic, 6}},
};

int rarityToNumber(Rarity rarity) {
  for (const auto &entry : rarityMap) {
    if (entry.second.first == rarity) {
      return entry.second.second;
    }
  }

  return 1;
}

Rarity numberToRarity(int number) {
  for (const auto &entry : rarityMap) {
    if (entry.second.second == number) {
      return entry.second.first;
    }
  }

  return Rarity::Common;
}

std::string rarityToString(Rarity rarity) {
  for (const auto &entry : rarityMap) {
    if (entry.second.first == rarity) {
      return entry.first;
    }
  }

  return "Unknown";
}

Rarity stringToRarity(const std::string &str) {
  auto it = rarityMap.find(str);

  if (it != rarityMap.end()) {
    return it->second.first;
  } else {
    return Rarity::Common;
  }
}
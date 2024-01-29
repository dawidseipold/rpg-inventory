#ifndef RARITY_CONVERTER_H
#define RARITY_CONVERTER_H

#include <map>
#include <string>

#include "rarity.h"

int rarityToNumber(Rarity rarity);
Rarity numberToRarity(int number);
std::string rarityToString(Rarity rarity);
Rarity stringToRarity(const std::string &str);

#endif // RARITY_CONVERTER_H

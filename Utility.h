#pragma once

#include <vector>
#include <memory>
#include "Item.h"


std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num);

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num);

std::vector<std::unique_ptr<Item>> makeAttackItems(int num);

struct Character;
std::string getCharacterStats(const Character* ch);

void useDefensiveItem(Character*, Item*);
void useHelpfulItem(Character*, Item*);
void useAttackItem(Character*, Item*);

int diceRoll(int nTimes = 1, int nFaces = 6);

void levelUpStat(int& stat, int& initialStat);

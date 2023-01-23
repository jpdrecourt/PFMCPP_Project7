#include "Paladin.h"
#include "Utility.h"

Paladin::Paladin(std::string name_, int hp, int armor_, int attackDamage_) :
    Character(hp, armor_, attackDamage_),
    name(name_)
{
    helpfulItems = makeHelpfulItems(diceRoll());
    defensiveItems = makeDefensiveItems(diceRoll());
}


Paladin::~Paladin() {}

const std::string& Paladin::getName() const
{
    return name;
}

std::string Paladin::getStats() const
{
    return getCharacterStats(this);
}

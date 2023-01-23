#include "Dwarf.h"
#include "Utility.h"

Dwarf::Dwarf(std::string name_, int hp, int armor_, int attackDamage_) :
    Character(hp, armor_, attackDamage_),
    name(name_)
{
    helpfulItems = makeHelpfulItems(diceRoll());
    defensiveItems = makeDefensiveItems(diceRoll());
}

Dwarf::~Dwarf() 
{}

const std::string& Dwarf::getName() const
{
    return name;
}

std::string Dwarf::getStats() const
{
    return getCharacterStats(this);
}

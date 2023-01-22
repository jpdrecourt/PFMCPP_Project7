#include "Paladin.h"
#include "Utility.h"

Paladin::Paladin(std::string name_, int hp, int armor_, int attackDamage_) :
    Character(hp, armor_, attackDamage_),
    name(name_)
{}

Paladin::~Paladin() {}

const std::string& Paladin::getName() 
{
    return name;
}

std::string Paladin::getStats() 
{
    return getCharacterStats(this);
}

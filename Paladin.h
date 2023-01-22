#pragma once

#include "Character.h"

struct Paladin : Character
{
Paladin(std::string name_, int hp, int armor_, int attackDamage_ = 0);
~Paladin() override;

const std::string& getName() override;

std::string getStats() override;

private:
    const std::string name;
};

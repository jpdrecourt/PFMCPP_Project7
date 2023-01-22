#pragma once

#include "Character.h"

struct Dwarf : Character
{
Dwarf(std::string name_, int hp, int armor_, int attackDamage_ = 0);
~Dwarf() override;

const std::string& getName() override;

std::string getStats() override;

private:
    const std::string name;
};

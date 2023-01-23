#pragma once

#include "Character.h"

struct Dwarf : Character
{
Dwarf(std::string name_, int hp, int armor_, int attackDamage_ = 4);
~Dwarf() override;

const std::string& getName() const override;

std::string getStats() const override;

private:
    const std::string name;
};

#pragma once

#include "Character.h"

struct Paladin : Character
{
Paladin(std::string name_, int hp, int armor_, int attackDamage_ = 10);
~Paladin() override;

const std::string& getName() const override;

std::string getStats() const override;

private:
    const std::string name;
};

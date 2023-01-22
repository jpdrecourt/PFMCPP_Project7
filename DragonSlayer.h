#pragma once

#include "Character.h"

struct DragonSlayer : Character
{
    DragonSlayer(std::string name_, int hp, int armor_, int attackDamage_ = 0);
    ~DragonSlayer() override;

    const std::string& getName() override;

    std::string getStats() override;

    void attack(Character& other) override;

private:
    const std::string name;
};

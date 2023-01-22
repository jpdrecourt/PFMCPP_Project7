#pragma once

#include "Character.h"

struct Dragon : Character
{
    Dragon(std::string name_, int hp, int armor_, int attackDamage_ = 0);
    ~Dragon() override;

    void attack(Character& other) override;

    const std::string& getName() override;

    std::string getStats() override;

private:
    const std::string name;
};


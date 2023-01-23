#pragma once

#include "Character.h"

struct Dragon : Character
{
    Dragon(std::string name_, int hp, int armor_, int attackDamage_ = 80);
    ~Dragon() override;

    void attack(Character& other) override;

    const std::string& getName() const override;

    std::string getStats() const override;

private:
    const std::string name;
};


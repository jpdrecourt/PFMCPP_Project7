#pragma once

#include "Character.h"

struct DragonSlayer : Character
{
    DragonSlayer(std::string name_, int hp, int armor_, int attackDamage_ = 4);
    ~DragonSlayer() override;

    const std::string& getName() const override;

    std::string getStats() const override;

    void attack(Character& other) override;

private:
    const std::string name;
};

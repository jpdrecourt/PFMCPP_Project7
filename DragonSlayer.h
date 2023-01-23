#pragma once

#include "Character.h"

struct AttackItem;

struct DragonSlayer : Character
{
    DragonSlayer(std::string name_, int hp, int armor_, int attackDamage_ = 4);
    ~DragonSlayer() override;

    const std::string& getName() const override;

    std::string getStats() const override;

    void attack(Character& other) override;

    AttackItem& getAttackItem() const { return *attackItem; }

private:
    const std::string name;
    std::unique_ptr<AttackItem> attackItem;
};

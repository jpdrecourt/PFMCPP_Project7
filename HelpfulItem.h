#pragma once

#include "Item.h"
#include "Character.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"

struct HelpfulItem : Item
{
    HelpfulItem() : Item("helpful item", 2) { }
    ~HelpfulItem() override {};
    void use(Character* character) override;
};


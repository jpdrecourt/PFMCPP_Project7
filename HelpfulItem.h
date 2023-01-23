#pragma once

#include "Item.h"

struct Character;

struct HelpfulItem : Item
{
    HelpfulItem() : Item("helpful item", 2) { }
    ~HelpfulItem() override {};
    void use(Character* character) override;
};


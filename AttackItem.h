#include "Item.h"

struct Character;

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 1) { }
    void use(Character* character) override;
};

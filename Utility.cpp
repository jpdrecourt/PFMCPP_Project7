#include <cstdlib>

#include "Utility.h"

#include "HelpfulItem.h"
#include "DefensiveItem.h"
#include "AttackItem.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"

std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- > 0 )
    {
        items.push_back( std::unique_ptr<HelpfulItem>(new HelpfulItem()) );
    }
    
    std::cout << "made " << items.size() << " helpful items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- > 0 )
    {
        items.push_back( std::unique_ptr<DefensiveItem>(new DefensiveItem()) );
    }
    
    std::cout << "made " << items.size() << " defensive items" << std::endl;
    return items;
}

std::string getCharacterStats(const Character* ch)
{
    std::string str;
    
    str += "    hitPoints: " + std::to_string(ch->getHP()) + "\n";
    str += "    armor: " + std::to_string(ch->getArmorLevel()) + "\n";
    str += "    attack damage: " + std::to_string(ch->getAttackDamage()) + "\n";
    str += "    is defending: " + std::string((ch->getIsDefending() ? "true" : "false" )) + "\n";
    str += "    " + std::to_string(ch->getHelpfulItems().size()) + " helpful items,  " + std::to_string(ch->getDefensiveItems().size()) + " defensive items";
    return str;
}

void useDefensiveItem(Character* character, Item* item)
{
    //dwarves, paladins, and DragonSlayers get extra boosts from defensive item.
    if( auto* ch0 = dynamic_cast<Dwarf*>(character) )
    {
        ch0->boostArmor( item->getBoost() * 1.1 );
    }
    else if( auto* ch1 = dynamic_cast<Paladin*>(character) )
    {
        //same with paladins
        ch1->boostArmor( item->getBoost() * 1.3 );
    }
    else if( auto* ch2 = dynamic_cast<DragonSlayer*>(character))
    {
        ch2->boostArmor( item->getBoost() * 1.5 );
    }
    else if( auto* ch3 = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't need defensive items
    }  
}
void useHelpfulItem(Character* character, Item* item)
{
    if( auto* ch0 = dynamic_cast<Dwarf*>(character) )
    {
        ch0->boostHitPoints(item->getBoost() * 2);
    }
    else if( auto* ch1 = dynamic_cast<Paladin*>(character) )
    {
        ch1->boostHitPoints(item->getBoost() * 1.5);
    }
    else if( auto* ch2 = dynamic_cast<DragonSlayer*>(character))
    {
        ch2->boostHitPoints(item->getBoost() * 1.25);
    }
    else if( auto* ch3 = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't carry helpful items!
    }
}
void useAttackItem(Character* character, Item* item)
{
    if( auto* ch0 = dynamic_cast<Dwarf*>(character) )
    {
        ch0->boostAttackDamage(item->getBoost() * 1.5);
    }
    else if( auto* ch1 = dynamic_cast<Paladin*>(character) )
    {
        ch1->boostAttackDamage(item->getBoost() * 1.33);
    }
    else if( auto* ch2 = dynamic_cast<DragonSlayer*>(character))
    {
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so their attack item should boost their attack damage by a factor of 10
        //this means you need to GET the attack damage, multiply it by the item's boost, and BOOST the attackDamage with that multiplied value.  
        //check Character.h for available member functions you can use.
        ch2->boostAttackDamage( ch2->getAttackDamage() * item->getBoost() );
    }
    else if( auto* ch3 = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't carry attack items!
    }
}

int diceRoll(int nTimes, int nFaces)
{
    int result = 0;
    
    for (int i = 0; i < nTimes; ++i)
        result += (rand() % nFaces) + 1;

    return result;        
}

void levelUpStat(int& stat, int& initialStat)
{
    if (stat < initialStat)
        stat = initialStat;
    
    stat *= 1.1;

    initialStat = stat;
}

#pragma once

#include <iostream>
#include "Monster.h"

void printMonster(Monster monster)
{
    std::cout << "This "
        << toString(monster.monsterType)
        << " is named "
        << monster.name
        << " and has "
        << monster.health
        << " health"
        << std::endl;
}

std::string toString(MonsterType type)
{
    switch(type)
    {
    case MonsterType::ORGE:
        return "Orge";
    case MonsterType::GOBLIN:
        return "Goblin";
    case MonsterType::SKELETON:
        return "Skeleton";
    case MonsterType::ORK:
        return "Ork";
    case MonsterType::TROLL:
        return "Troll";
    default:
        return "";
    }
};

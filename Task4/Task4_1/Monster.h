#pragma once

#include <string>

enum class MonsterType
{
    ORGE,
    GOBLIN,
    SKELETON,
    ORK,
    TROLL
};

struct Monster
{
    std::string name;
    int16_t health;
    MonsterType monsterType;
};

void printMonster(Monster monster);
std::string toString(MonsterType type);


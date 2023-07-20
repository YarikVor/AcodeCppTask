#include "Monster.h"

#include "../MonsterType.h"
#include <iostream>
#include <string>
#include <array>

std::string toString(const MonsterType monsterType)
{
    static const int maxLen = static_cast<int>(MonsterType::MAX_MONSTER_TYPES);
    static const std::array<std::string, maxLen> names
    {
        "Dragon",
		"Goblin",
		"Ogre",
		"Orc",
		"Skeleton",
		"Troll",
		"Vampire",
		"Zombie",
    };
    static const int len = sizeof(names) / sizeof(names[0]);
    static_assert(len == maxLen);

    int index = static_cast<int>(monsterType);

    if(index < 0 || index >= len)
        return "";

    return names[index];
}

Monster::Monster(
    MonsterType monsterType,
    std::string name,
    int health
    ) :
    m_monsterType(monsterType),
    m_name(name),
    m_health(health)
{
    //ctor
}

Monster::~Monster()
{
    //dtor
}

void Monster::print()
{
    using namespace std;

    cout
        << m_name
        << " is the "
        << toString(m_monsterType)
        << " that has "
        << m_health
        << " health points"
        << endl;

}

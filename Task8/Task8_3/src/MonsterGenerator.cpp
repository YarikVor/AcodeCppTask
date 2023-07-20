#include "MonsterGenerator.h"
#include "../fun.h"

const std::array<std::string, 6> MonsterGenerator::s_names =
{
    "Jini",
    "Max",
    "Sik",
    "Fonta",
    "Git",
    "Mizuki"
};

Monster MonsterGenerator::generateMonster()
{
    auto monsterType = randomMonsterType();
    auto name = s_names[getRandomNumber(0, 5)];
    auto health = getRandomNumber(1, 100);

    return Monster(monsterType, name, health);
}

MonsterType MonsterGenerator::randomMonsterType()
{
    int randomValue = getRandomNumber(0, static_cast<int>(MonsterType::MAX_MONSTER_TYPES));

    return static_cast<MonsterType>(randomValue);
}



#include "MonsterFactory.h"
#include "../Random.h"

#include <assert.h>

Monster MonsterFactory::monsterData[MonsterFactory::typeLength]
{
    Monster("dragon", 'D', 20, 4, 100),
    Monster("orc", 'o', 4, 2, 25),
    Monster("slime", 's', 1, 1, 10)
};

Monster MonsterFactory::getMonster(MonsterFactory::Type type)
{
    int index = static_cast<int>(type);

    assert(0 <= index && index < typeLength);

    return monsterData[index];
}



MonsterFactory::Type MonsterFactory::randType()
{
    int randValue = Random::randInt(0, typeLength - 1);

    assert(0 <= randValue && randValue < typeLength);

    return static_cast<Type>(randValue);
}

Monster MonsterFactory::randMonster()
{
    Type type = randType();

    return getMonster(type);
}

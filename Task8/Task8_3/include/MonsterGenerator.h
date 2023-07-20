#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

#include "Monster.h"
#include "../MonsterType.h"

class MonsterGenerator
{
public:
    static const std::array<std::string, 6> s_names;
    static Monster generateMonster();
    static MonsterType randomMonsterType();
    static int randomHealth();
    MonsterGenerator() = delete;
protected:

private:

};

#endif // MONSTERGENERATOR_H

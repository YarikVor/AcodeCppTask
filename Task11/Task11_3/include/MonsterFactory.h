#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include "Monster.h"

class MonsterFactory
{
public:
    enum class Type
    {
        DRAGON,
        ORC,
        SLIME,
        END_ENUM
    };
    static const int typeLength = static_cast<int>(Type::END_ENUM);
    static Monster getMonster(Type type);
    static Monster randMonster();
    static Type randType();

    public:
        MonsterFactory() = delete;

    protected:

    private:
        static Monster monsterData[typeLength];
};

#endif // MONSTERFACTORY_H

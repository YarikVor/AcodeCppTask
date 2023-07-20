#ifndef MONSTER_H
#define MONSTER_H

#include "../MonsterType.h"
#include <string>
#include <array>

class Monster
{
    public:
        Monster(MonsterType monsterType, std::string name, int health);
        virtual ~Monster();
        void print();

    protected:

    private:
        MonsterType m_monsterType;
        std::string m_name;
        int m_health;
};

#endif // MONSTER_H

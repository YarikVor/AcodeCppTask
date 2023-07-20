#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "Creature.h"

class Monster : public Creature
{

public:
    Monster (
        std::string name,
        char symbol,
        int health,
        int damage,
        int money);

protected:

private:
};

#endif // MONSTER_H

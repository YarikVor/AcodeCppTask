#include <iostream>
#include "Monster.h"

using namespace std;

int main()
{
    Monster goblin {"John", 170, MonsterType::GOBLIN};
    Monster orc{"James", 35, MonsterType::ORK};

    printMonster(goblin);
    printMonster(orc);

    std::system("pause");

    return 0;
}

#include <iostream>
#include <random>
#include <time.h>

#include "Monster.h"
#include "MonsterGenerator.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand();

    Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}

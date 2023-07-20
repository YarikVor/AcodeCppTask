#include <iostream>
#include <random>
#include <time.h>

#include "Monster.h"
#include "MonsterGenerator.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // ���������� ��������� ���� � �������� ���������� ��������
	rand();

    Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}

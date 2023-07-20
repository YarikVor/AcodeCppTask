#include "Monster.h"

Monster::Monster (
    std::string name,
    char symbol,
    int health,
    int damage,
    int money)
    : Creature(name, symbol, health, damage, money) {}

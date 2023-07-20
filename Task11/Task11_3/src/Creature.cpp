#include "Creature.h"

Creature::Creature(
    std::string name,
    char symbol,
    int health,
    int damage,
    int money)
    : m_name(name),
    m_char(symbol),
    m_health(health),
    m_damage(damage),
    m_money(money)
{
}

void Creature::reduceHealth(int damage)
{
    m_health -= damage;
}

bool Creature::isDead() const
{
    return m_health <= 0;
}

void Creature::addGold(int money)
{
    m_money += money;
}

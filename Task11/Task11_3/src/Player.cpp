#include "Player.h"

Player::Player(std::string name): Creature(name, '@', 10, 1, 0)
{
}

void Player::levelUp()
{
    m_level += 1;
    m_damage += 1;
}

bool Player::hasWon() const
{
    return m_level >= 20;
}

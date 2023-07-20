#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
public:
    Creature(
        std::string name,
        char symbol,
        int health,
        int damage,
        int money);
    std::string getName() const { return m_name; }
    char getChar() const { return m_char; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getMoney() const { return m_money; }

    void reduceHealth(int damage);
    bool isDead() const;
    void addGold(int money);

protected:
    std::string m_name;
    char m_char;
    int m_health;
    int m_damage;
    int m_money;
};

#endif // CREATURE_H

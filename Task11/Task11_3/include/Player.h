#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Creature.h"

class Player: public Creature
{
    public:
        Player(std::string name);
        int getLevel() const {return m_level;}
        void levelUp();
        bool hasWon() const;

    protected:

    private:
        int m_level = 1;
};

#endif // PLAYER_H

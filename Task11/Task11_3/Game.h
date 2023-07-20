#pragma once

#include <iostream>

#include "Player.h"
#include "Monster.h"

namespace Game
{
    using namespace std;

    Player createPlayer();
    char getAction();
    void printEncountered(const Monster &monster);
    void printSuccessfullyFled();
    void printKill(const Monster &monster);
    void printNowLevel(const Player &player);
    void printHitDamage(const Monster &monster, const Player &player);
    void printMonsterDamage(const Monster &monster);
    void printWin(const Player &player);
    void printLoss(const Player &player);
    void printStatusPlayer(const Player &player);
}

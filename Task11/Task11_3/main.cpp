#include <iostream>
#include <string>

#include <time.h>

#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "MonsterFactory.h"
#include "Random.h"

#include "Game.h"

using namespace std;



int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    Player player = Game::createPlayer();

    while(true)
    {
        Monster monster = MonsterFactory::randMonster();
        Game::printEncountered(monster);

        while(true)
        {
            Game::printStatusPlayer(player);
            char doing = Game::getAction();
            system("cls");

            if(doing == 'R')
            {
                if(Random::isInPercentile(50))
                {
                    Game::printSuccessfullyFled();
                    break;
                }
            }
            else if (doing == 'F')
            {
                Game::printHitDamage(monster, player);
                monster.reduceHealth(player.getDamage());
                if(monster.isDead())
                {
                    Game::printKill(monster);
                    player.levelUp();
                    player.addGold(monster.getMoney());
                    Game::printNowLevel(player);

                    if(player.hasWon())
                    {
                        Game::printWin(player);
                        return 0;
                    }
                    break;
                }
            }
            else
            {
                throw "Error";
            }

            player.reduceHealth(monster.getDamage());
            Game::printMonsterDamage(monster);

            if(player.isDead())
            {
                Game::printLoss(player);

                return 0;
            }
        }

    }

    return 0;
}

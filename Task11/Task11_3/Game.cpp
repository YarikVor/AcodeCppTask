#include "Game.h"

Player Game::createPlayer()
{
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    cout << "Welcome, "
         << playerName
         << endl;

    return Player(playerName);
}

char Game::getAction()
{
    char doing;

    do
    {
        cout << "Run(R) or Fight(F): ";
        cin >> doing;
    }
    while (doing != 'R' && doing != 'F');

    return doing;
}

void Game::printEncountered(const Monster &monster)
{
    cout << "You have encountered a "
         << monster.getName()
         << " ("
         << monster.getChar()
         << ")."
         << endl;
}

void Game::printSuccessfullyFled()
{
    cout << "You successfully fled."
         << endl;
}

void Game::printKill(const Monster &monster)
{
    cout << "You killed the "
         << monster.getName()
         << "."
         << endl;

    cout << "You found "
         << monster.getMoney()
         << " gold."
         << endl;
}

void Game::printNowLevel(const Player &player)
{
    cout << "You are now level "
         << player.getLevel()
         << "."
         << endl;
}

void Game::printHitDamage(const Monster &monster, const Player &player)
{
    cout << "You hit the "
         << monster.getName()
         << " for "
         << player.getDamage()
         << " damage."
         << endl;
}

void Game::printMonsterDamage(const Monster &monster)
{
    cout << "The "
         << monster.getName()
         << " hit you for "
         << monster.getDamage()
         << " damage."
         << endl;
}

void Game::printWin(const Player &player)
{
    cout << "You win! Money: "
         << player.getMoney()
         << endl;
}

void Game::printLoss(const Player &player)
{
    cout << "You loss... Level: "
         << player.getLevel()
         << ", money: "
         << player.getMoney()
         << endl;
}

void Game::printStatusPlayer(const Player &player)
{
    cout << "Health: "
        << player.getHealth()
        << endl;
}

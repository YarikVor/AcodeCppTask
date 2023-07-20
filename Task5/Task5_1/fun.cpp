#pragma once

#include <iostream>
#include "fun.h"

void printYourGuess(const char* text)
{
    std::cout << "Your guess is too "
        << text
        << "."
        << std::endl;
}

void printYourGuessIsTooHighOrLow(bool isHigh)
{
    auto text = isHigh ? "high" : "low";
    printYourGuess(text);
}

int inputGuess(int attempt)
{
    std::cout << "Guest #"
        << attempt
        << ": ";
    int result;
    std::cin >> result;
    return result;
}

bool isExit()
{
    char symbol;
    while(true) {
        std::cout << "Would you like to play again (y/n)? ";

        std::cin >> symbol;

        if(symbol == 'y')
            return false;
        if(symbol == 'n')
            return true;
    }
}

void printEndGame()
{
    std::cout << "Thank you for playing." << std::endl;
}

void printHeader()
{
    std::cout << "Let's play a game. I'm thinking"
        "of a number. You have 7 tries to guess what it is."
        << std::endl;
}

void printWin()
{
    std::cout << "Correct! You win!" << std::endl;
}

void printLoss(int value)
{
    std::cout << "Sorry, you lose. The correct number was "
        << value
        << "."
        << std::endl;
}

void pause()
{
    std::system("pause");
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

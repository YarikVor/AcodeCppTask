#include <iostream>
#include <ctime>
#include <cstdlib>

#include "fun.h"

using namespace std;

const int minRandom = 1;
const int maxRandom = 100;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    do
    {
        printHeader();
        int value;
        int randValue = getRandomNumber(minRandom, maxRandom);

        int attempt = 1;
        for(; attempt <= countTrying; attempt++)
        {
            value = inputGuess(attempt);

            if(value == randValue)
            {
                printWin();
                break;
            }
            else
            {
                printYourGuessIsTooHighOrLow(value > randValue);
            }
        }
        if(attempt == countTrying + 1)
        {
            printLoss(randValue);
        }

    } while (!isExit());

    printEndGame();

    pause();

    return 0;
}

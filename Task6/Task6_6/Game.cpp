#include <iostream>

#include "Deck.h"
#include "Card.h"

bool isWin(const int playerRank, const int dillerRank)
{
    return playerRank <= 21
        && (
            dillerRank > 21
            || playerRank > dillerRank
        );
}

bool playBackjack(const Deck &deck)
{
    using namespace std;

    const Card *cardPtr = &(deck[0]);

    int playerRank = 0;
    int dillerRank = 0;

    dillerRank += getCardValue(*(cardPtr++));

    playerRank += getCardValue(*(cardPtr++));

    char symbol;
    do
    {
        playerRank += getCardValue(*(cardPtr++));

        if(playerRank > 21)
            break;

        cout << "Your points: "
            << playerRank
            << endl
            << "Hit(h) or stand(s)? ";

        cin >> symbol;

    } while (symbol != 's');

    while(dillerRank < 17)
        dillerRank += getCardValue(*(cardPtr++));

    cout << "Your points: "
        << playerRank
        << endl
        << "Diller's points: "
        << dillerRank
        << endl;

    return isWin(playerRank, dillerRank);
}

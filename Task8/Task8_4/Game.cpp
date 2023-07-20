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

bool playBackjack(Deck &deck)
{
    using namespace std;

    int playerRank = 0;
    int dillerRank = 0;

    dillerRank += deck.dealCard().getCardValue();
    playerRank += deck.dealCard().getCardValue();

    char symbol;
    do
    {
        playerRank += deck.dealCard().getCardValue();

        if(playerRank > 21)
            break;

        cout << "Your points: "
            << playerRank
            << endl
            << "Hit(h) or stand(s)? ";

        cin >> symbol;

    } while (symbol != 's');

    while(dillerRank < 17)
        dillerRank += deck.dealCard().getCardValue();

    cout << "Your points: "
        << playerRank
        << endl
        << "Diller's points: "
        << dillerRank
        << endl;

    return isWin(playerRank, dillerRank);
}

#include <iostream>
#include <string>
#include <array>
#include <time.h>

#include "CardSuit.h"
#include "CardRank.h"
#include "Card.h"

#include "Deck.h"

#include "Game.h"

using namespace std;

int main()
{
    srand(time(0));

    Deck deck = Deck::createRandDeck();

    const char *textInfo = playBackjack(deck)
        ? "Player win"
        : "Diller win";

    cout << textInfo;

    return 0;
}

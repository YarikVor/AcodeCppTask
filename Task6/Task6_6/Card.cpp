#pragma once

#include <string>

#include "Card.h"
#include "CardSuit.h"
#include "CardRank.h"


std::string toShortString(const Card &card)
{
    using namespace std;

    string suit = toShortString(card.suit);
    string rank = toShortString(card.rank);

    return suit + rank;
}

int getCardValue(const Card card)
{
    static int rankToIntArray[] {
        2, 3, 4, 5, 6, 7, 8, 9, 10,
        10, 10, 10,
        11
    };

    return rankToIntArray[static_cast<int>(card.rank)];
}

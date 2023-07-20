#pragma once

#include <string>

#include "CardSuit.h"
#include "CardRank.h"

class Card
{
public:
    Card(
        CardRank rank = CardRank::MAX,
        CardSuit suit = CardSuit::MAX
    );
    std::string toShortString() const;
    void printCard() const;
    int getCardValue() const;
private:
    CardSuit m_suit;
    CardRank m_rank;
};



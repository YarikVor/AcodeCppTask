#pragma once

#include <string>

#include "CardSuit.h"
#include "CardRank.h"

struct Card
{
    CardSuit suit;
    CardRank rank;
};

std::string toShortString(const Card &card);
int getCardValue(const Card card);

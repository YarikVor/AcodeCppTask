#pragma once

#include <string>
#include <iostream>

#include "Card.h"
#include "CardSuit.h"
#include "CardRank.h"

Card::Card(CardRank rank, CardSuit suit)
    : m_rank(rank), m_suit(suit)
{};

std::string Card::toShortString() const
{
    using namespace std;

    string suit = ::toShortString(m_suit);
    string rank = ::toShortString(m_rank);

    return suit + rank;
}

int Card::getCardValue() const
{
    static const int rankToIntArray[]
    {
        2, 3, 4, 5, 6, 7, 8, 9, 10,
        10, 10, 10,
        11
    };

    return rankToIntArray[static_cast<int>(m_rank)];
}

void Card::printCard() const
{
    std::cout << toShortString();
}

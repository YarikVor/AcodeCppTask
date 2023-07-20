#pragma once

#include <array>
#include "Card.h"

class Deck
{
public:
    static const int deckSize = 52;
    static Deck createDeck();
    static Deck createRandDeck();

    Deck();

    void rand(const int countLoops = deckSize);
    void reset();
    void init();
    void print() const;
    Card getRandomCard() const;
    const Card& dealCard();

private:

    std::array<Card, deckSize> m_deck;
    int m_cardIndex = 0;

};

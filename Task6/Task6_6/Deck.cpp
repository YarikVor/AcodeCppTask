
#include <iostream>

#include "Deck.h"

void printDeck(const Deck &cards)
{
    for(const auto &card : cards)
    {
        std::cout << toShortString(card) << " ";
    }
}

void randDeck(Deck &cards, const int countRand)
{
    for(int i = 0; i < countRand; ++i)
    {
        int indexX = rand() % deckSize;
        int indexY = rand() % deckSize;

        std::swap(cards[indexX], cards[indexY]);
    }
}

Card getRandomCard(const Deck &deck)
{
    int index = rand() % deckSize;

    return deck[index];
}

void initDeck(Deck &deck)
{
    int countSuit = static_cast<int>(CardSuit::MAX);
    int countRank = static_cast<int>(CardRank::MAX);

    for(int rank = 0, index = 0; rank < countRank; ++rank)
    {
        Card card {
            CardSuit::CLUB,
            static_cast<CardRank>(rank)
        };

        for(int suit = 0; suit < countSuit; ++suit, ++index)
        {
            card.suit = static_cast<CardSuit>(suit);
            deck[index] = card;
        }
    }
}

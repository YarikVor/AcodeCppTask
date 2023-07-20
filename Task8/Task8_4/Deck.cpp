
#include <iostream>
#include <random>

#include "Deck.h"

Deck::Deck()
{

}

Deck Deck::createDeck()
{
    Deck deck;
    deck.init();
    return deck;
}

Deck Deck::createRandDeck()
{
    auto deck = createDeck();
    deck.rand();
    return deck;
}

void Deck::print() const
{
    for(const auto &card : m_deck)
    {
        std::cout << card.toShortString() << " ";
    }
    std::cout << std::endl;
}

void Deck::rand(const int countRand)
{
    reset();

    for(int i = 0; i < countRand; ++i)
    {
        int indexX = std::rand() % deckSize;
        int indexY = std::rand() % deckSize;

        std::swap(m_deck[indexX], m_deck[indexY]);
    }
}

Card Deck::getRandomCard() const
{
    int index = std::rand() % deckSize;
    return m_deck[index];
}

void Deck::init()
{
    int countSuit = static_cast<int>(CardSuit::MAX);
    int countRank = static_cast<int>(CardRank::MAX);

    for(int rank = 0, index = 0; rank < countRank; ++rank)
    {
        for(int suit = 0; suit < countSuit; ++suit, ++index)
        {
            Card card(
                static_cast<CardRank>(rank),
                static_cast<CardSuit>(suit)
            );
            m_deck[index] = card;
        }
    }
}

void Deck::reset()
{
    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    return m_deck[m_cardIndex++];
}

#pragma once

#include <array>

#include "Card.h"

const int deckSize = 52;
using Deck = std::array<Card, deckSize>;

void printDeck(const Deck &cards);
void randDeck(Deck &cards, const int countRand = deckSize);
Card getRandomCard(const Deck &deck);
void initDeck(Deck &deck);

#pragma once

#include <string>

enum class CardSuit
{
    CLUB,
    DIAMONT,
    HEART,
    SPIDER,
    MAX
};

std::string toShortString(const CardSuit suit);

#pragma once

#include <string>

#include "CardSuit.h"

std::string toShortString(const CardSuit suit)
{
    switch(suit)
    {
    case CardSuit::CLUB:
        return "C";
    case CardSuit::DIAMONT:
        return "D";
    case CardSuit::HEART:
        return "H";
    case CardSuit::SPIDER:
        return "S";
    default:
        return "";
    }
}

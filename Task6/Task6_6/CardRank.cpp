#pragma once

#include <string>

#include "CardRank.h"

std::string toShortString(const CardRank suit)
{
    static std::string arrayChars[] {
        "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "J", "Q", "K",
        "A"
    };
    const int len = sizeof(arrayChars) / sizeof(arrayChars[0]);

    int index = static_cast<int>(suit);

    return (0 <= index && index < len) ? arrayChars[index] : "";
}





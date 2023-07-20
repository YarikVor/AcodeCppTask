#pragma once

enum class CardRank
{
    RANG_2,
    RANG_3,
    RANG_4,
    RANG_5,
    RANG_6,
    RANG_7,
    RANG_8,
    RANG_9,
    RANG_10,
    RANG_J,
    RANG_Q,
    RANG_K,
    RANG_A,
    MAX
};

std::string toShortString(const CardRank suit);


#pragma once

enum class CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_J,
    RANK_Q,
    RANK_K,
    RANK_A,
    MAX
};

std::string toShortString(const CardRank suit);


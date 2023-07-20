#pragma once

#include <string>
#include "Pair.h"

template <typename TSecond>
class StringValuePair: public Pair<std::string, TSecond>
{
public:
    StringValuePair(const std::string& key, const TSecond& value)
        : Pair<std::string, TSecond>(key, value)
    {
    }
};


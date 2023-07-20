#pragma once

template <typename TFirst, typename TSecond>
class Pair
{
public:
    Pair(const TFirst &first, const TSecond &second)
        : m_first(first), m_second(second) {};
    TFirst first() const
    {
        return m_first;
    }
    TSecond second() const
    {
        return m_second;
    }

private:
    TFirst m_first;
    TSecond m_second;

};

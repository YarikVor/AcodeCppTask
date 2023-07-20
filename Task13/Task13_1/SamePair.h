#pragma once

template <typename T>
class SamePair
{
public:
    SamePair(const T &first, const T &second)
        : m_first(first), m_second(second) {};
    T first() const
    {
        return m_first;
    }
    T second() const
    {
        return m_second;
    }

private:
    T m_first;
    T m_second;
};

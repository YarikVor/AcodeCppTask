#include "../include/Average.h"


int Average::operator()() const
{
    return m_sum / m_count;
}

Average& Average::operator+=(const int value)
{
    ++m_count;
    m_sum += value;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Average &average)
{
    out << static_cast<double>(average.m_sum) / average.m_count;

    return out;
}


#include "../include/FixedFloat.h"
#include <cassert>
#include <cmath>


FixedFloat::FixedFloat(int16_t whole, int8_t dec)
    : m_whole(whole), m_decimal(dec)
{
    assert(-99 <= dec && dec <= 99);

    if(dec < 0 || whole < 0)
    {
        if(dec > 0)
            m_decimal = -dec;
        else if(whole > 0)
            m_whole = -whole;
    }
}

FixedFloat::FixedFloat(double number)
{
    assert(INT16_MIN <= number && number <= INT16_MAX);
    m_whole = static_cast<int16_t>(number);
    m_decimal = std::round((number - m_whole) * 100);
}

FixedFloat::operator double() const
{
    return m_whole + m_decimal / 100.0d;
}

bool FixedFloat::operator== (const FixedFloat &fixedFloat) const
{
    return m_decimal == fixedFloat.m_decimal && m_whole == fixedFloat.m_whole;
}

std::istream& operator >> (std::istream& in, FixedFloat& fixedFloat)
{
    double value;
    std::cin >> value;
    fixedFloat = FixedFloat(value);

    return in;
}

FixedFloat FixedFloat::operator-() const
{
    return FixedFloat(-m_whole, -m_decimal);
}

FixedFloat FixedFloat::operator+(const FixedFloat &fixedFloat) const
{
    int32_t sumWhole = m_whole + fixedFloat.m_whole;
    int16_t sumDec = m_decimal + fixedFloat.m_decimal;

    if(sumDec >= 100)
    {
        sumDec -= 100;
        ++sumWhole;
    }
    else if(sumDec <= -100)
    {
        sumDec += 100;
        --sumWhole;
    }

    if(sumWhole > 0 && sumDec < 0)
    {
        sumDec += 100;
        --sumWhole;
    }
    else if(sumWhole < 0 && sumDec > 0)
    {
        sumDec -= 100;
        ++sumWhole;
    }

    return FixedFloat(sumWhole, sumDec);
}


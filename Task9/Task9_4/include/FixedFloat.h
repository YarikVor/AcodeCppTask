#ifndef FIXEDFLOAT_H
#define FIXEDFLOAT_H

#include <cstdint>
#include <iostream>

class FixedFloat
{
    public:
        FixedFloat(int16_t whole = 0, int8_t dec = 0);
        FixedFloat(double number);

        operator double() const;

        bool operator== (const FixedFloat &fixedFloat) const;
        friend std::istream& operator >> (std::istream& in, FixedFloat& fixedFloat);
        FixedFloat operator-() const;
        FixedFloat operator+(const FixedFloat &fixedFloat) const;

    protected:

    private:
        int16_t m_whole;
        int8_t m_decimal;
};

#endif // FIXEDFLOAT_H

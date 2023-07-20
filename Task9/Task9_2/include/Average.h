#ifndef AVERAGE_H
#define AVERAGE_H

#include <cstdint>
#include <iostream>

class Average
{
    public:
        int operator()() const;
        Average& operator+=(const int32_t value);
        friend std::ostream& operator<<(std::ostream& out, const Average& average);
    private:
        int32_t m_sum = 0;
        int8_t m_count = 0;
};

#endif // AVERAGE_H

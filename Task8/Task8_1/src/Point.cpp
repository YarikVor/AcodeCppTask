#include "Point.h"

#include <iostream>
#include <cmath>

Point::Point(double a, double b): m_a(a), m_b(b)
{

}

void Point::print() const
{
    std::cout << "Point("
        << m_a
        << ", "
        << m_b
        << ")"
        << std::endl;
}

double Point::distanceTo(const Point &point) const
{
    const double difA = m_a - point.m_a;
    const double difB = m_b - point.m_b;
    return std::sqrt(difA * difA + difB * difB);
}

double distanceFrom(const Point &from, const Point &to)
{
    const double difA = from.m_a - to.m_a;
    const double difB = from.m_b - to.m_b;
    return std::sqrt(difA * difA + difB * difB);
}

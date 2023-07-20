#include "Circle.h"

Circle::Circle(Point center, int radius): m_center(center), m_radius(radius)
{
    //ctor
}

Circle::~Circle()
{
}

void Circle::print(std::ostream &out) const
{
   out << "Circle("
        << m_center
        << ", radius "
        << m_radius
        << ")"
        << std::endl;
}

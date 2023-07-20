#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c): m_a(a), m_b(b), m_c(c)
{

}

Triangle::~Triangle()
{

}

void Triangle::print(std::ostream &out) const
{
    out << "Triangle("
        << m_a
        << ", "
        << m_b
        << ", "
        << m_c
        << ")"
        << std::endl;
}

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Shape.h>
#include <Point.h>

class Triangle: public Shape
{
    public:
        Triangle(Point a, Point b, Point c);
        virtual ~Triangle() override;
        virtual void print(std::ostream &out) const override;

    private:
        Point m_a;
        Point m_b;
        Point m_c;
};

#endif // TRIANGLE_H

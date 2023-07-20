#ifndef CIRCLE_H
#define CIRCLE_H

#include <Point.h>
#include <Shape.h>

class Circle: public Shape
{
    public:
        Circle(Point point, int radius);
        virtual ~Circle() override;
        virtual void print(std::ostream &out) const override;
        int getRadius() const {return m_radius;};

    private:
        Point m_center;
        int m_radius;
};

#endif // CIRCLE_H

#ifndef SHAPE_H
#define SHAPE_H

#include <ostream>

class Shape
{
    public:
        virtual ~Shape();
        virtual void print(std::ostream &out) const = 0;
        friend std::ostream& operator<<(std::ostream &out, const Shape &shape);
};

#endif // SHAPE_H

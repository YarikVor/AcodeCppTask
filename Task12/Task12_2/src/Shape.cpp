#include "Shape.h"

std::ostream& operator<<(std::ostream &out, const Shape &shape)
{
    shape.print(out);
    return out;
}

Shape::~Shape()
{

}

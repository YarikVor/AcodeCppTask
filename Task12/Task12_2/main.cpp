#include <iostream>
#include <vector>

#include <Shape.h>
#include <Point.h>
#include <Triangle.h>
#include <Circle.h>

int getLargestRadius(std::vector<Shape*> &v)
{
    int maxRadius = INT32_MIN;

    for(auto const &shape : v)
    {
        // var circle = shape as Circle; // (C#)
        auto circle = dynamic_cast<Circle*>(shape);

        if(circle != nullptr)
        {
            int radius = circle->getRadius();
            if (radius > maxRadius)
                maxRadius = radius;
        }
    }

    return maxRadius;
}

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

    for(Shape *elem: v)
        std::cout << *elem << std::endl;

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию

    for(auto const &elem: v)
        delete elem;
}

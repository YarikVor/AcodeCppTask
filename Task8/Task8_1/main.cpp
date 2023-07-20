#include <iostream>

#include "Point.h"

using namespace std;

int main()
{
    Point first;
    Point second(2, 5);

    first.print();
    second.print();

     cout << "Distance between two points: "
        << first.distanceTo(second)
        << endl;

     cout << "Distance between two points: "
        << distanceFrom(first, second)
        << endl;

    return 0;
}

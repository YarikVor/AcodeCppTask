#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point
{
    public:
        Point(int x, int y, int z);
        friend std::ostream& operator<<(std::ostream &out, const Point &p);

    protected:

    private:
        int m_x;
        int m_y;
        int m_z;

};

#endif // POINT_H

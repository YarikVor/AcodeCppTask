#pragma once

class Point
{
    public:
        Point(double a = 0, double b = 0);
        void print() const;
        double distanceTo(const Point &point) const;
        friend double distanceFrom(const Point &from, const Point &to);
    protected:

    private:
        double m_a = 0.0;
        double m_b = 0.0;
};

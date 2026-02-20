#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
private:
    Fixed x;
    Fixed y;
public:
    Point();
    Point(const Point& other);
    Point(const float x, const float y);
    Fixed getX()const;
    Fixed getY()const;
    Point& operator=(const Point& other);
    ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
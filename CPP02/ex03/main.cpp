#include "Point.hpp"
Fixed calculate_triangle_area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
    return ((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))* Fixed(0.5f));
}
Fixed absFixed(Fixed x)
{
    if (x < Fixed(0))
        return x * Fixed(-1);
    return x;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed A_ABC = absFixed(calculate_triangle_area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY()));
    Fixed A_PAB = absFixed(calculate_triangle_area(point.getX(), point.getY(), a.getX(), a.getY(), b.getX(), b.getY()));
    Fixed A_PBC = absFixed(calculate_triangle_area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY()));
    Fixed A_PAC = absFixed(calculate_triangle_area(point.getX(), point.getY(), a.getX(), a.getY(), c.getX(), c.getY()));
    Fixed sum = A_PAB + A_PAC + A_PBC;
    if (A_PAB == 0|| A_PAC == 0 || A_PBC == 0)
        return (false);
    return (absFixed(sum - A_ABC) < Fixed(0.01f));
}

int main( void )
{
    Point a(2, 1);
    Point b(1, 2);
    Point c(1, -2);
    Point p(1.3f, 0.2f);

    if (bsp(a, b, c, p))
        std::cout << "Inside the triangle!\n";
    else
        std::cout << "Outside the triangle!\n";
    return 0;
}
#include "Point.hpp"
int main( void )
{
    Point a(2, 1);
    Point b(1, 2);
    Point c(1, -2);
    Point p(0, 0);

    if (bsp(a, b, c, p))
        std::cout << "Inside the triangle!\n";
    else
        std::cout << "Outside the triangle!\n";
    return 0;
}
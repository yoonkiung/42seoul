#include "Point.hpp"

Fixed func(Point x, Point y, Point a)
{
    Fixed temp((a.get_x() - x.get_x()) * (x.get_y() - y.get_y()) 
            - (a.get_y() - x.get_y()) * (x.get_x() - y.get_x()));
    return (temp);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (func(a, b, c) * func(a, b, point) > 0 &&
        func(b, c, a) * func(b, c, point) > 0 &&
        func(a, c, b) * func(a, c, point) > 0)
        return (true);
    return(false);
}
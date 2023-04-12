#include <iostream>
#include "Point.hpp"

int main( void ) {
    Point A(0, 0);
    Point B(0, 3);
    Point C(4, 0);
    Point point(1, 1);
    
    std::cout << bsp(A, B, C, point) << std::endl;
}
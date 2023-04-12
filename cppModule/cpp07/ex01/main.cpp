#include "iter.hpp"

int main()
{
    int intarr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float floatarr[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    iter(intarr, 10, print);
    std::cout << std::endl;
    iter(intarr, 10, add);
    iter(intarr, 10, print);
    std::cout << std::endl;
    iter(floatarr, 10, print);
    std::cout << std::endl;
    iter(floatarr, 10, add);
    iter(floatarr, 10, print);
}
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange bit;   

    if (ac != 2)
        std::cout << "Error: File not exsit" << std::endl;
    else
        bit.printInfo(av[1]);
}
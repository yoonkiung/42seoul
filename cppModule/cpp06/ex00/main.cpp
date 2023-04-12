#include "Convert.hpp"

int main(int ac, char **av)
{
    
    if (ac != 2)
    {
        std::cout << "Argument error" << std::endl;
        return (1);
    }
    
    std::string arg = av[1];
    std::cout.precision(1);
    std::cout << std::fixed;

    Convert convert(arg);
    convert.convertChar();
    convert.convertInt();
    convert.convertFloat();
    convert.convertDouble();

    return (0);
}
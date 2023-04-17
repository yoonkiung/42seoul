#include "RPN.hpp"

int main(int ac, char **av)
{

    RPN rpn;
    
    if (ac != 2)
        std::cout << "Error: bad argument" << std::endl;
    else
    {
        if (!rpn.setAv(av[1]))
        {
            std::cout << "Error: bad argument" << std::endl;
            return (0);
        }
    }
    // rpn.parsingDebug();
    if (!rpn.calculate())
        std::cout << "Error: bad operation" << std::endl;
}
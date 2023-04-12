#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    
    {
        try
        {
            Bureaucrat me("kiyoon", 1);
            Form form("contract", 10, 10);

            me.signForm(form);
            std::cout << form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        
    }
    std::cout << "\n************************\n\n";
    {
        try
        {
            Bureaucrat me("kiyoon", 11);
            Form form("contract", 10, 10);

            me.signForm(form);
            std::cout << form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
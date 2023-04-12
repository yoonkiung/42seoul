#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    
    {
        Bureaucrat me("kiyoon", 1);
        Bureaucrat you("seung", 150);

        std::cout << me << std::endl;

        me.increaseGrade();
        you.decreaseGrade();
        
        std::cout << me.getGrade() << std::endl;
        std::cout << you.getGrade() << std::endl;
    }
    std::cout << "*******************" << std::endl;
    {
        try
        {
            Bureaucrat me("kiyoon", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            Bureaucrat me("kiyoon", 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
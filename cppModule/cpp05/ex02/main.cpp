#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        try
        {
            Bureaucrat me("kiyoon", 138);
            Form *form = new ShrubberyCreationForm("Shru name");

            me.signForm(*form);
            me.executeForm(*form);
            std::cout << *form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "\n*************" << std::endl;
    {
        try
        {
            Bureaucrat me("kiyoon", 1);
            Form *form = new RobotomyRequestForm("Robo name");

            me.signForm(*form);
            me.executeForm(*form);
            std::cout << *form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "\n*************" << std::endl;
    {
        try
        {
            Bureaucrat me("kiyoon", 1);
            Form *form = new PresidentialPardonForm("Pres name");

            me.signForm(*form);
            me.executeForm(*form);
            std::cout << *form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
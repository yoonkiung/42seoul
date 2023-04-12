#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    {
        Intern intern;

        Form *shur = intern.makeForm("shrubbery creation", "A");
        Form *robo = intern.makeForm("robotomy request", "B");
        Form *pres = intern.makeForm("presidential pardon", "C");

        std::cout << *shur << std::endl;
        std::cout << *robo << std::endl;
        std::cout << *pres << std::endl;

        delete shur;
        delete robo;
        delete pres;
    }
    std::cout << "\n\n***********\n\n";
    {
        Intern intern;

        Form *fail = intern.makeForm("abcabcabc", "A");
        std::cout << fail << std::endl;
    }
}
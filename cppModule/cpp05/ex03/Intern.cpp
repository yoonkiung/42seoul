#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int turnInt(std::string name)
{
	if (name == "shrubbery creation")
		return (SHURBERRY);
	else if (name == "robotomy request")
		return (ROBOTOMY);
	else if (name == "presidential pardon")
		return (PRESIDENTIAL);
	return (UNKNOWN);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form *temp = NULL;

	switch (turnInt(name))
	{
	case SHURBERRY:
		temp = new ShrubberyCreationForm(target);
		break;

	case ROBOTOMY:
		temp = new RobotomyRequestForm(target);
		break;

	case PRESIDENTIAL:
		temp = new PresidentialPardonForm(target);
		break;
	}

	if (temp == NULL)
		std::cout << "Intern can not create" << std::endl;
	else
		std::cout << "Intern create" << std::endl;
	return (temp);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shr", 145, 137), _target("default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : Form("shr", 145, 137), _target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form(src), _target(src._target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "name : " 
	  << i.getName() << std::endl
	  << "grade to sign : "
	  << i.getGradeToSign() << std::endl
	  << "grade to execute : "
	  << i.getGradeToExecute();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->_is_signed || executor.getGrade() > this->_grade_to_execute)
		throw UnExecutableException();
	else
	{
		std::cout << "     *     " << std::endl;
		std::cout << "    /*\\    " << std::endl;
		std::cout << "   /***\\   " << std::endl;
		std::cout << "  /*****\\  " << std::endl;
		std::cout << " /*******\\ " << std::endl;
		std::cout << "    | |    " << std::endl;
		std::cout << "    | |    " << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
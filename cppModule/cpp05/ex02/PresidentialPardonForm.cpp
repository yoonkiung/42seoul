#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("Pres", 25, 5), _target("default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : Form("Pres", 25, 5), _target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : Form(src), _target(src._target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->_is_signed || executor.getGrade() > this->_grade_to_execute)
		throw UnExecutableException();
	else
	{
		std::cout << _target
				  << "has been  pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
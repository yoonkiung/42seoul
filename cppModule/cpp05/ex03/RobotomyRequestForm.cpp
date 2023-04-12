#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("rob", 72, 45), _target("default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) :Form("rob", 72, 45), _target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form(src), _target(src._target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->_is_signed || executor.getGrade() > this->_grade_to_execute)
		throw UnExecutableException();
	else
	{
		std::cout << "drilllllll....l.lllll" << std::endl;
		std::srand(time(NULL));
		if (std::rand() % 2 == 0)
		{
			std::cout << _target
					  << " has been robotomized successfully" << std::endl;
		}
		else
			std::cout << "robotomy failed" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("default"), _is_signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute) : _name(_name), _grade_to_sign(_grade_to_sign), _grade_to_execute(_grade_to_execute)
{
	if (_grade_to_execute < 1 || _grade_to_sign < 1)
		throw Form::GradeTooHighException();
	else if (_grade_to_execute > 150 || _grade_to_sign > 150)
		throw Form::GradeTooLowException();
	else
		_is_signed = false;
}

Form::Form( const Form & src ) : _name(src._name), _is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
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

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high!!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low!!";
}

const char* Form::UnExecutableException::what() const throw()
{
	return "Form cannot be execute";
}

void Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_is_signed);
}

int Form::getGradeToSign() const
{
	return (_grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (_grade_to_execute);
}

/* ************************************************************************** */
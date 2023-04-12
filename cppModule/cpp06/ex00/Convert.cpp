#include "Convert.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Convert::Convert()
{
}

Convert::Convert(std::string arg) : _value(arg)
{
	try
	{
		if (_is_char(arg))
			_doubleValue = static_cast<double>(arg[0]);
		else
			_doubleValue = std::stod(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Argument error" << std::endl;
	}
}

Convert::Convert( const Convert & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Convert::~Convert()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Convert &				Convert::operator=( Convert const & rhs )
{
	if ( this != &rhs )
	{
		this->_value = rhs._value;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool Convert::_is_char(std::string arg)
{
	if (arg.length() == 1 && isalpha(arg[0]))
		return (true);
	return (false);
}

void Convert::convertInt()
{
	if (isnan(_doubleValue) || isinf(_doubleValue))
		std::cout << "int: impossible" << std::endl;
	else
	{
		std::cout << "int: "
				  << static_cast<int>(_doubleValue) << std::endl;
	}
}

void Convert::convertFloat()
{
	std::cout << "float: "
			  << static_cast<float>(_doubleValue)
			  << "f" << std::endl;
}

void Convert::convertChar()
{
	if (isnan(_doubleValue) || isinf(_doubleValue))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(_doubleValue)))
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		std::cout << "char: '"
				  << static_cast<char>(_doubleValue) 
				  << "'"<< std::endl;
	}		
}

void Convert::convertDouble()
{
	std::cout << "double: "
			  << _doubleValue << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->_av = rhs.getAv();
		this->stack = rhs.getStack();
		this->_token = rhs.getToken();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RPN::parsingDebug()
{
	std::vector<std::string>::iterator iter;

	for (iter = _token.begin(); iter != _token.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}

void	RPN::parsing(std::string av)
{
	std::string delim;
	std::stringstream iss(av);

	while (iss >> delim)
		_token.push_back(delim);
}

int	RPN::isAllNum(std::string str)
{
	if (str.length() == 1 && str[0] >= '0' && str[0] <= '9')
		return (1);
	if (str.length() == 2 && (str[0] == '-' || str[0] == '+') && str[1] >= '0' && str[1] <= '9')
		return (1);
	return (0);
}

int RPN::isOnlyOperator(std::string str)
{
	if (str.length() != 1)
		return (0);
	if (str[0] == '-' || str[0] == '+' || str[0] == '*' || str[0] == '/')
		return (1);
	return (0);
}

int	RPN::check()
{
	std::vector<std::string>::iterator iter;
	for (iter = _token.begin(); iter != _token.end(); iter++)
	{
		if (((*iter).length() == 2 && ((*iter)[0] == '+' || (*iter)[0] == '-')) || \
			((*iter)[0] >= '0' && (*iter)[0] <= '9'))
		{
			if (!isAllNum(*iter))
				return (0);
		}
		else
		{
			if (!isOnlyOperator(*iter))
				return (0);
		}
	}
	if (_token.size() <= 2)
		return (0);
	if (!((_token[0].length() == 2 && (_token[0][0] == '+' || _token[0][0] == '-')) || \
		(_token[0][0] >= '0' && _token[0][0] <= '9')))
		return (0);
	if (!((_token[1].length() == 2 && (_token[1][0] == '+' || _token[1][0] == '-')) || \
		(_token[1][0] >= '0' && _token[1][0] <= '9')))
		return (0);
	if ((_token[_token.size() - 1].length() == 2 && (_token[_token.size() - 1][0] == '+' || _token[_token.size() - 1][0] == '-')) || \
		(_token[_token.size() - 1][0] >= '0' && _token[_token.size() - 1][0] <= '9'))
		return (0);
	return (1);
}

int	RPN::isInInt(int a, int b, std::string oper)
{
	long long long_a;
	long long long_b;

	long_a = static_cast<long long>(a);
	long_b = static_cast<long long>(b);

	if (oper == "+")
	{
		if (long_a + long_b > INT_MAX || long_a + long_b < INT_MIN)
			return (0);
	}
	else if (oper == "-")
	{
		if (long_a - long_b > INT_MAX || long_a - long_b < INT_MIN)
			return (0);
	}
	else if (oper == "*")
	{
		if (long_a * long_b > INT_MAX || long_a * long_b < INT_MIN)
			return (0);
	}
	else if (oper == "/")
	{
		if (long_a / long_b > INT_MAX || long_a / long_b < INT_MIN)
			return (0);
	}
	return (1);
}

int	RPN::operation(std::string oper)
{
	int a;
	int b;
	if (stack.size() < 2)
		return (0);
	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();
	if (oper == "+")
	{
		if (!isInInt(a, b, "+"))
			return (0);
		stack.push(a + b);
	}
	else if (oper == "-")
	{
		if (!isInInt(a, b, "-"))
			return (0);
		stack.push(a - b);
	}
	else if (oper == "*")
	{
		if (!isInInt(a, b, "*"))
			return (0);
		stack.push(a * b);
	}
	else if (oper == "/")
	{
		if (b == 0 || !isInInt(a, b, "/"))
			return (0);
		stack.push(a / b);	
	}
	return (1);
}

int	RPN::calculate()
{
	std::vector<std::string>::iterator iter;
	int	temp_number;
	for (iter = _token.begin(); iter != _token.end(); iter++)
	{
		std::stringstream ss(*iter);

		if (((*iter).length() == 2 && ((*iter)[0] == '+' || (*iter)[0] == '-')) || \
			((*iter)[0] >= '0' && (*iter)[0] <= '9'))
		{
			
			ss >> temp_number;
			stack.push(temp_number);
		}
		else
		{
			if (!operation(*iter))
				return (0);
		}
	}
	if (stack.size() != 1)
		return (0);
	std::cout << stack.top() << std::endl;
	return (1);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	RPN::setAv(std::string av)
{
	this->_av = av;
	parsing(av);
	if (!check())
		return (0);
	return (1);
}

std::string RPN::getAv() const
{
	return (this->_av);
}

std::stack<int> RPN::getStack() const
{
	return (this->stack);
}

std::vector<std::string>  RPN::getToken() const
{
	return (this->_token);
}
/* ************************************************************************** */
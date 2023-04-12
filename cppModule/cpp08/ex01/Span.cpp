#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span( const Span & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_n = rhs._n;
		this->_deq = rhs._deq;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Span const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char* Span::SpanNotFound::what() const throw()
{
	return "Not enough element";
}

void Span::addNumber(int n)
{
	if (_deq.size() >= _n)
		throw FullSpanException();
	else
		_deq.push_back(n);
}

void Span::addNumberRange(std::deque<int> &temp)
{
	if (temp.size() + _deq.size() > _n)
		throw FullSpanException();
	else
		_deq.insert(_deq.begin(), temp.begin(), temp.end());
}

unsigned int Span::shortestSpan()
{
	if (_deq.size() == 0 || _deq.size() == 1)
		throw SpanNotFound();
	else
	{
		unsigned int min = UINT_MAX;
		std::sort(_deq.begin(), _deq.end(), comp);
		
		for (size_t i = 0; i < _deq.size() - 1; i++)
		{
			if (static_cast<unsigned int>(_deq[i + 1] - _deq[i]) < min)
				min = _deq[i + 1] - _deq[i];
		}
		return (min);
	}
}

unsigned int Span::longestSpan()
{
	if (_deq.size() == 0 || _deq.size() == 1)
		throw SpanNotFound();
	else
	{
		std::sort(_deq.begin(), _deq.end(), comp);
		return (_deq.back() - _deq.front());	
	}
}

bool comp(int a, int b)
{
	if (a < b)
		return (true);
	return (false);
}

/* ************************************************************************** */
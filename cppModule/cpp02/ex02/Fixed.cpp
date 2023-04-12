#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const int val)
{
	value = val << fract;
}

Fixed::Fixed(const float val)
{
	value = roundf(val * static_cast<float>(1 << fract));
}

Fixed::Fixed( const Fixed & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs) {
		value = rhs.getRawBits();
	}
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs)
{
	if (this->toFloat() > rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &rhs)
{
	if (this->toFloat() < rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &rhs)
{
	if (this->toFloat() >= rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &rhs)
{
	if (this->toFloat() <= rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &rhs)
{
	if (this->toFloat() == rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &rhs)
{
	if (this->toFloat() != rhs.toFloat())
		return (true);
	return (false);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed temp(this->toFloat() + rhs.toFloat());
	return (temp);
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed temp(this->toFloat() - rhs.toFloat());
	return (temp);
}


Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed temp(this->toFloat() * rhs.toFloat());
	return (temp);
}


Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed temp(this->toFloat() / rhs.toFloat());
	return (temp);
}

Fixed& Fixed::operator++()
{
	value++;
	return (*this);
}

Fixed& Fixed::operator++(int)
{
	Fixed &temp(*this);
	value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	value--;
	return (*this);
}

Fixed& Fixed::operator--(int)
{
	Fixed &temp(*this);
	value--;
	return (temp);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << fract));
}

int Fixed::toInt(void) const
{
	return (value >> fract);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return(a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return(a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return(a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return(a);
	return (b);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits( void ) const
{
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}


/* ************************************************************************** */
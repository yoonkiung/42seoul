#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point(Fixed& x, Fixed& y) : x(x), y(y)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point & src) : x(src.x), y(src.y)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point  & i )
{
	o << "(" << i.get_x() << ", " << i.get_y() << ")";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed const Point::get_x()
{
	return x;
}

Fixed const Point::get_y()
{
	return y;
}

/* ************************************************************************** */
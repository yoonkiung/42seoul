#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{

	public:

		Point(Fixed& x, Fixed& y);
		Point(const float x, const float y);
		Point( Point const & src );
		~Point();

		Point &		operator=( Point const & rhs );

		Fixed const get_x();
		Fixed const get_y();
	private:
		const Fixed x;
		const Fixed y;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */
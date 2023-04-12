#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
	private:
		int value;
		static const int fract = 8;

};

#endif /* *********************************************************** FIXED_H */
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed(const int val);
		Fixed(const float val);

		Fixed(Fixed const & src);
		~Fixed();

		Fixed &operator=(Fixed const &rhs);

		bool operator>(Fixed const &rhs);
		bool operator<(Fixed const &rhs);
		bool operator>=(Fixed const &rhs);
		bool operator<=(Fixed const &rhs);
		bool operator==(Fixed const &rhs);
		bool operator!=(Fixed const &rhs);
		
		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;

		Fixed& operator++();
		Fixed& operator++(int);
		Fixed& operator--();
		Fixed& operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed & max(const Fixed &a, const Fixed &b);

	private:
		int value;
		static const int fract = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif /* *********************************************************** FIXED_H */
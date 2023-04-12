#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>

class Convert
{

	public:

		Convert();
		Convert(std::string arg);
		Convert( Convert const & src );
		~Convert();

		Convert &		operator=( Convert const & rhs );

		void convertInt();
		void convertFloat();
		void convertChar();
		void convertDouble();
		
	private:
		std::string _value;
		double _doubleValue;
		bool _is_char(std::string arg);

};


#endif /* ********************************************************* CONVERT_H */
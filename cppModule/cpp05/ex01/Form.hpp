#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	public:

		Form();
		Form(std::string _name, int _grade_to_sigh, int _grade_to_execute);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );
		
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat bur);
	
	private:

		const std::string _name;
		bool _is_signed;
		const int _grade_to_sign;
		const int _grade_to_execute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
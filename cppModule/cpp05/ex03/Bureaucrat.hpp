#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
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

		Bureaucrat();
		Bureaucrat(std::string _name);
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string getName() const;
		int getGrade() const;

		void increaseGrade();
		void decreaseGrade();
		void signForm(Form &form);
		void executeForm(Form const & form);

	private:
		
		const std::string _name;
		int _grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );


#endif /* ****************************************************** BUREAUCRAT_H */
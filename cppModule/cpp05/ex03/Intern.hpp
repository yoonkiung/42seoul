#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define SHURBERRY 0
# define ROBOTOMY 1
# define PRESIDENTIAL 2
# define UNKNOWN 3

class Form;

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		Form *makeForm(std::string name, std::string target);

	private:

};

#endif /* ********************************************************** INTERN_H */
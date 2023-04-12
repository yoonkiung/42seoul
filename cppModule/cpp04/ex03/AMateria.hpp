#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{

	public:
		AMateria();
		AMateria(std::string _type);
		AMateria( AMateria const & src );
		virtual ~AMateria();
		
		AMateria &			operator=( AMateria const & rhs );

		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) { (void)target; };

	protected:
		std::string _type;
};

#endif /* ******************************************************** AMATERIA_H */
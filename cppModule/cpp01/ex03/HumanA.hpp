#ifndef HUMANAA_HPP
# define HUMANAA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();


	private:
		Weapon &weapon;
		std::string name;
};


#endif /* ********************************************************** HUMANA_H */
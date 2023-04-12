#ifndef HUMANAB_HPP
# define HUMANAB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{

	public:

		HumanB(std::string name);
		~HumanB();

		void attack();
		void setWeapon(Weapon &weapon);
	private:
		Weapon *weapon;
		std::string name;

};


#endif /* ********************************************************** HUMANA_H */
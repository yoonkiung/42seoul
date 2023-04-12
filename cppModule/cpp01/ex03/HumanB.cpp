#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name) : name(name)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanB::attack()
{
	std::cout << name 
			  << " attacks with their " 
			  << weapon->getType() 
			  << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

/* ************************************************************************** */
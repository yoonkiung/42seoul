#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name) 
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanA::attack()
{
	std::cout << name 
			  << " attacks with their " 
			  << weapon.getType() 
			  << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
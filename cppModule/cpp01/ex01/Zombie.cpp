#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie(){}

Zombie::Zombie(std::string name) : name(name) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie()
{
	std::cout << name << " is dead....... ):" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Zombie::announce(void)
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Zombie::set_name(std::string name)
{
	this->name = name;
}
/* ************************************************************************** */
#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	name = "default FragTrap";
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << name
			  << " is created (Frag)" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << name
			  << " is created (Frag)" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
{
	*this = src;
	std::cout << name
			  << " is copyed (Frag)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << name
			  << " is destoried (Frag)" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->hit_point = rhs.hit_point;
		this->energy_point = rhs.energy_point;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << "name : " << i.get_name() << std::endl;
	o << "hit_point : " << i.get_hit_point() << std::endl;
	o << "energy_point : " << i.get_energy_point() << std::endl;
	o << "attack_damage : " << i.get_attack_damage() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void)
{
	std::cout << "positive high fives request" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
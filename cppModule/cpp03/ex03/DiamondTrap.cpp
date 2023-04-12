#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	name = "default DiamondTrap";
	energy_point = 50;
	ClapTrap::name = name + "_clap_name";
	std::cout << name
			  << " is created (Diamond)" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(name)
{
	energy_point = 50;
	ClapTrap::name = name + "_clap_name";
	std::cout << name
			  << " is created (Diamond)" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	*this = src;
	std::cout << name
			  << " is copyed (Diamond)" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << name
			  << " is destoried (Diamond)" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
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

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
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

void DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap::name : "
			  << ClapTrap::name << std::endl;
	std::cout << "name : "
			  << name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	DiamondTrap::get_name() const
{
	return (name);
}

/* ************************************************************************** */
#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap()
{
	name = "default ScavTrap";
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << name
			  << " is created (Scav)" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << name
			  << " is created (Scav)" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	*this = src;
	std::cout << name
			  << " is copyed (Scav)" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << name
			  << " is destoried (Scav)" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
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

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
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

void ScavTrap::attack(const std::string& target)
{
	if (energy_point == 0)
	{
		std::cout << "ScavTrap "
			  << name 
			  << " does not have enough energy to attack" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap "
			  << name 
			  << " attacks "
			  << target
			  << ", causing "
			  << attack_damage
			  <<" points of damage!" << std::endl;
		energy_point--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
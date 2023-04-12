#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	name = "default ClapTrap";
	hit_point = 10;
	energy_point = 10;
	attack_damage = 0;
	std::cout << name
			  << " is created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	hit_point = 10;
	energy_point = 10;
	attack_damage = 0;
	std::cout << name
			  << " is created" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	*this = src;
	std::cout << name
			  << " is copyed" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << name
			  << " is destoried" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
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

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
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

void ClapTrap::attack(const std::string& target)
{
	if (energy_point == 0)
	{
		std::cout << "ClapTrap "
			  << name 
			  << " does not have enough energy to attack" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap "
			  << name 
			  << " attacks "
			  << target
			  << ", causing "
			  << attack_damage
			  <<" points of damage!" << std::endl;
		energy_point--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point < amount)
		hit_point = 0;
	else
		hit_point -= amount;
	
	std::cout << name 
			  << " take Damage "
			  << amount
			  << ", now hit_point is "
			  << hit_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_point == 0)
	{
		std::cout << "ClapTrap "
			  << name 
			  << " does not have enough energy to repair" << std::endl;
	}
	else
	{
		hit_point += amount;
		energy_point--;
		std::cout << "ClapTrap "
			  << name 
			  << " repair itself "
			  << amount
			  << ", now hit_point is "
			  << hit_point << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ClapTrap::get_name() const
{
	return (name);
}

unsigned int ClapTrap::get_hit_point() const
{
	return (hit_point);
}

unsigned int ClapTrap::get_energy_point() const
{
	return (energy_point);
}

unsigned int ClapTrap::get_attack_damage() const
{
	return (attack_damage);
}

/* ************************************************************************** */
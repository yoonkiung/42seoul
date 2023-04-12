#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : ICharacter()
{
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character(std::string _name) : ICharacter(), _name(_name)
{
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character( const Character & src )
{
	this->_name = src._name;
	std::memcpy(this->_inventory, src._inventory, sizeof(this->_inventory));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &		Character::operator=( Character const & rhs )
{
	this->_name = rhs._name;
	std::memcpy(this->_inventory, rhs._inventory, sizeof(this->_inventory));
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	int i;
	for (i = 0; i < 4; i++)
		if (_inventory[i] == NULL)
			break;

	if (i == 4)
		std::cout << "inventory is full" << std::endl;
	else
		_inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (_inventory[idx] == NULL)
		std::cout << "the slot "
				  << idx
				  << " is already empty" << std::endl;
	else
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << "slot number error" << std::endl;
	else if (_inventory[idx] == NULL)
		std::cout << "slot is empty" << std::endl;
	else
		_inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const
{
	return (_name);
}

/* ************************************************************************** */
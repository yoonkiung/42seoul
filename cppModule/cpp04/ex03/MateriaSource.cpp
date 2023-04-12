#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource() : IMateriaSource()
{
	std::memset(_inventory, 0, sizeof(_inventory));
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	std::memcpy(this->_inventory, src._inventory, sizeof(this->_inventory));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		std::memcpy(this->_inventory, rhs._inventory, sizeof(this->_inventory));
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *materia)
{
	int i;
	for (i = 0; i < 4; i++)
		if (_inventory[i] == NULL)
			break;
	if (i == 4)
	{
		std::cout << "inventory is full" << std::endl;
		delete materia;
	}
	else
		_inventory[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *temp = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL && type == _inventory[i]->getType())
		{	
			temp = _inventory[i]->clone();
			break;
		}
	}
	return (temp);
}




/* ************************************************************************** */
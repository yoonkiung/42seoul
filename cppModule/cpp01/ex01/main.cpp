#include "Zombie.hpp"

int main()
{
	Zombie *first_group = zombieHorde(5, "first_group");
	Zombie *second_group = zombieHorde(5, "second_group");
	
	for (int i = 0; i < 5; i++)
		first_group[i].announce();
	for (int i = 0; i < 5; i++)
		second_group[i].announce();

	delete[] first_group;
	delete[] second_group;
	return (0);
}
#include "Zombie.hpp"

int main()
{
	Zombie *first_zombie = newZombie("first");
	first_zombie->announce();
	
	randomChump("second");
	delete first_zombie;
	
	Zombie third_zombie("third");
	third_zombie.announce();
	return (0);
}
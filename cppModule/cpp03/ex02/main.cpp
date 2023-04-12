#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap A("A");
    FragTrap B("B");

    std::cout << A << std::endl;
    std::cout << B << std::endl;

    A.attack("B");
    B.takeDamage(A.get_attack_damage());
    B.attack("A");
    A.takeDamage(B.get_attack_damage());

    std::cout << A << std::endl;
    std::cout << B << std::endl;

    A.beRepaired(1);
    std::cout << A << std::endl;
    std::cout << B << std::endl;

    B.highFivesGuys();
    return (0);
}
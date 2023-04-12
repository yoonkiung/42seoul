#include "ClapTrap.hpp"

int main()
{
    ClapTrap A("A");
    ClapTrap B("B");

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
    return (0);
}
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmerge;
    if (ac == 1 || !pmerge.setContainers(ac, av))
    {
        std::cout << "Error" << std::endl;
        return (0);
    }

    pmerge.printSequence("Before");
    pmerge.sorting(ac);
    pmerge.printSequence("After");
    pmerge.printTimeDeque(ac);
    pmerge.printTimeList(ac);
}

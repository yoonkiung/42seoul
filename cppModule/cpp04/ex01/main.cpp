#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    {
        std::cout << "```````Test 1````````\n" << std::endl;
        const Animal* j = new Dog(); 
        const Animal* i = new Cat();

        delete j;//should not create a leak delete i;
        delete i;
    }
    {
        std::cout << "\n\n```````Test 2````````\n" << std::endl;
        const Dog* j = new Dog(); 
        Dog i(*j);

        std::cout << &(j->brain) << std::endl;
        std::cout << &(i.brain) << std::endl;
        
        delete j;//should not create a leak delete i;
    }
    system("leaks a.out");
    return 0; 
}
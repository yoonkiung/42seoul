#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << j->getType() 
                  << " " 
                  << std::endl; std::cout 
                  << i->getType() 
                  << " " 
                  << std::endl; 
        
        i->makeSound();
        // const Animal animal();
        delete j;
        delete i;
    }
    return 0; 
}
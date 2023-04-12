#include <iostream>

int main()
{
	std::string init = "HI THIS IS BRAIN";
	std::string *stringPTR = &init;
	std::string &stringREF = init;

	std::cout << "The memory address of the string variable  " << &init << std::endl;
	std::cout << "The memory address held by stringPTR       " << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF       " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "The of the string variable  " << init << std::endl;
	std::cout << "The held by stringPTR       " << *stringPTR << std::endl;
	std::cout << "The held by stringREF       " << stringREF << std::endl;
}
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string temp;
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

    while (true)
    {
        std::cout << "input : ";
        std::getline(std::cin, temp);
		if(std::cin.fail())
		{
			std::cout << std::endl;
			break ;
		}
        if (temp == "ADD")
        {
            std::cout << "first_name : ";
            std::getline(std::cin, first_name);
			if(std::cin.fail())
			{
				std::cout << std::endl;
				break ;
			}
            std::cout << "last_name : ";
            std::getline(std::cin, last_name);
			if(std::cin.fail())
			{
				std::cout << std::endl;
				break ;
			}
            std::cout << "nick_name : ";
            std::getline(std::cin, nick_name);
			if(std::cin.fail())
			{
				std::cout << std::endl;
				break ;
			}
            std::cout << "phone_number : ";
            std::getline(std::cin, phone_number);
			if(std::cin.fail())
			{
				std::cout << std::endl;
				break ;
			}
            std::cout << "darkest_secret : ";
            std::getline(std::cin, darkest_secret);
			if(std::cin.fail())
			{
				std::cout << std::endl;
				break ;
			}
            if (!phonebook.add_contact(first_name, last_name, nick_name, phone_number, darkest_secret))
				std::cout << "invalid" << std::endl;
        }
        else if (temp == "SEARCH")
            phonebook.search_contact();
        else if (temp == "EXIT")
            return (0);
        else
            std::cout << "invalid" << std::endl;
    }
    return (1);
}
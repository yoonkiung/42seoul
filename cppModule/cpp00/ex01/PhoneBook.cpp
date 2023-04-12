#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    cur_index = 0;
}

bool PhoneBook::is_valid_string(std::string input)
{
	if (input.begin() == input.end())
		return(false);
	for(int i = 0; i < static_cast<int>(input.length()); i++)
	{
		if (!isprint(input[i]))
			return (false);
	}
	return (true);
}

bool PhoneBook::is_valid_input(std::string first_name, 
							   std::string last_name, 
							   std::string nick_name, 
							   std::string phone_number,
							   std::string darkest_secret)
{
	if (!is_valid_string(first_name))
		return (false);
	if (!is_valid_string(last_name))
		return (false);
	if (!is_valid_string(nick_name))
		return (false);
	if (!is_valid_string(phone_number))
		return (false);
	if (!is_valid_string(darkest_secret))
		return (false);
	return (true);
}

bool PhoneBook::add_contact(std::string first_name, 
						 	std::string last_name, 
						 	std::string nick_name, 
						 	std::string phone_number,
						 	std::string darkest_secret)
{
	if (!is_valid_input(first_name, last_name, nick_name, phone_number, darkest_secret))
		return (false);
	if (first_name.length() >= 10)
    {
        first_name.erase(9, first_name.length() - 1);
        first_name.insert(9, ".");

    }
    if (last_name.length() >= 10)
    {
        last_name.erase(9, last_name.length() - 1);
        last_name.insert(9, ".");
    }
    if (nick_name.length() >= 10)
    {
        nick_name.erase(9, nick_name.length() - 1);
        nick_name.insert(9, ".");
    }
    Contact new_contact = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
    contact[cur_index % 8] = new_contact;
    cur_index++;
	return (true);
}

void PhoneBook::search_contact()
{
    int i = 0;
	std::string temp;

    while (i < cur_index && i < 8)
    {
        std::cout << "|";
        std::cout.width(10);
        std::cout <<std::right << i + 1;
        std::cout << "|";
        std::cout.width(10);
        std::cout << contact[i].get_first_name();
        std::cout << "|";
        std::cout.width(10);
        std::cout << contact[i].get_last_name();
        std::cout << "|";
        std::cout.width(10);
        std::cout << contact[i].get_nick_name();
        std::cout << "|";
        std::cout << std::endl;
        i++;
    }
	if (cur_index == 0)
		return ;
	std::cout << "type index : ";
	std::getline(std::cin, temp);
	if(std::cin.fail())
	{
		std::cout << std::endl;
		exit(1);
	}
	else if(static_cast<int>(temp.length() != 1))
		std::cout << "invalid" << std::endl;
	else if (static_cast<int>(temp[0] - '0') > cur_index)
		std::cout << "invalid" << std::endl;
	else if (temp[0] > '8')
		std::cout << "invalid" << std::endl;
	else
	{
		int index = static_cast<int>(temp[0] - '0');
		std::cout << "first_name : " << contact[index - 1].get_first_name() << std::endl;
		std::cout << "last_name : " << contact[index - 1].get_last_name() << std::endl;
		std::cout << "nick_name : " << contact[index - 1].get_nick_name() << std::endl;
		std::cout << "phone_number : " << contact[index - 1].get_phone_number() << std::endl;
		std::cout << "darkest_secret : " << contact[index - 1].get_darkest_secret() << std::endl;
	}
}
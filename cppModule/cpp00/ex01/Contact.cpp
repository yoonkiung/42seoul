#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string first_name, 
				 std::string last_name, 
				 std::string nick_name, 
				 std::string phone_number, 
				 std::string darkest_secret) :
    first_name(first_name), last_name(last_name), nick_name(nick_name), phone_number(phone_number), darkest_secret(darkest_secret)
	{};

std::string Contact::get_first_name()
{
    return first_name;
}

std::string Contact::get_last_name()
{
    return last_name;
}

std::string Contact::get_nick_name()
{
    return nick_name;
}

std::string Contact::get_phone_number()
{
    return phone_number;
}

std::string Contact::get_darkest_secret()
{
    return darkest_secret;
}
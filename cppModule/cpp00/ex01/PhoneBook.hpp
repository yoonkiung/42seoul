#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        int cur_index;
        Contact contact[8];

		static bool is_valid_input(std::string first_name, 
							std::string last_name, 
							std::string nick_name, 
							std::string phone_number,
							std::string darkest_secret); 
		
		static bool is_valid_string(std::string input);
    
	public:
        PhoneBook();
        
        bool add_contact(std::string first_name, 
						 std::string last_name, 
						 std::string nick_name, 
						 std::string phone_number,
						 std::string darkest_secret);
        void search_contact();
};

#endif
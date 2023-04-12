#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "I love having  extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do !"
              << std::endl;
}
void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!"
              << std::endl;
}
void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
              << std::endl;
}
void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                &Harl::error};
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
			(this->*f[i])();
    }
}

int str_to_int(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return (-1);
}

void Harl::filter(std::string level)
{
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                &Harl::error};
	int lev = str_to_int(level);

	switch (lev)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		(this->*f[0])();
		std::cout << std::endl;
	
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		(this->*f[1])();
		std::cout << std::endl;

	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		(this->*f[2])();
		std::cout << std::endl;

	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		(this->*f[3])();
		std::cout << std::endl;
		break;

	case -1:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	
	default:
		break;
	}
}
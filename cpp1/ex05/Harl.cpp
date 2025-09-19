#include "Harl.hpp"

// CONSTRUCTOR - DESTRUCTOR /////////////////////

Harl::Harl(void)
{
	
}

Harl::~Harl(void)
{
	
}

// PUBLIC /////////////////////

void	Harl::complain(std::string level){
	std::string	list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	Harl harl;
	void (Harl::*tab[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == list[i])
		{
			(harl.*tab[i])();
			return;
		}
	}
	std::cout << "Wrong level entered, try again with: DEBUG, INFO, WARNING, or ERROR" << std::endl;
}

// PRIVATE /////////////////////

void	Harl::debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ears, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
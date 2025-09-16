#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <stdlib.h>

void	print_symbol(void)
{
	std::cout <<" ________" << std::endl;
	std::cout <<"(_]----[_)" << std::endl;
	std::cout <<".~ |.''.|" << std::endl;
	std::cout <<"~. |'..'|" << std::endl;
	std::cout <<"`~`----` " << std::endl;
}

int	main(void)
{
	std::string input;
	PhoneBook	phonebook;

	print_symbol();
	while (1)
	{
		std::cout << std::endl << "Enter a command: \033[1;32mADD\033[0m, \033[1;34mSEARCH\033[0m, or \033[1;31mEXIT\033[0m" << std::endl;
		if (!std::getline(std::cin, input))
			exit(1);
		if (input == "SEARCH" || input == "search")
			phonebook.search();
		else if (input == "ADD" || input == "add")
			phonebook.add();
		else if (input == "EXIT" || input == "exit")
			exit(0);
		else
			std::cout << "Wrong command, please try again." << std::endl;
	}
}

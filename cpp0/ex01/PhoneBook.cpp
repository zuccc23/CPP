#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	std::cout << "constructor" << std::endl;
	_contacts[0].setFname("01234567890");
	_contacts[1].setFname("012345");
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "destructor" << std::endl;
}


void	PhoneBook::display_contact_list(void)
{
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "         " << i << "|";
		std::cout << _contacts[i].getFname() << "|";
		std::cout << std::endl;
	}
	return;
}

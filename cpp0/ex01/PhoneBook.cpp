#include "PhoneBook.class.hpp"
#include <iostream>
#include <sstream>

// CONSTRUCTOR - DESTRUCTOR /////////////////////

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

// PUBLIC /////////////////////

void	PhoneBook::search(void)
{
	std::string	input;
	int	index = 0;

	std::cout << std::endl << "Which contact(index) are you looking for ?" << std::endl << std::endl;
	display_contact_list();
	while (1)
	{
		std::getline(std::cin, input);
		std::istringstream my_stream(input);
		my_stream >> index;
		if (!my_stream)
			std::cout << "The index entered is invalid. Try again with an index between 0-7" << std::endl;
		else if (index > 7 || index < 0)
			std::cout << "The index entered is invalid. Try again with an index between 0-7" << std::endl;
		else if (index >= 0 && index < 8)
		{
			display_contact(index);
			return;
		}
	}
}

void	PhoneBook::add(void)
{
	std::string	name;

	if (index >= 8)
		this->index = 0;

	std::cout << "First name: ";
	std::getline(std::cin, name);
	while (name.empty())
	{
		std::cout << "No category can be left empty, please enter something\n";
		std::getline(std::cin, name);
	}
	_contacts[index].setFname(name);

	std::cout << "Last name: ";
	std::getline(std::cin, name);
	while (name.empty())
	{
		std::cout << "No category can be left empty, please enter something\n";
		std::getline(std::cin, name);
	}
	_contacts[index].setLname(name);

	std::cout << "Nickname: ";
	std::getline(std::cin, name);
	while (name.empty())
	{
		std::cout << "No category can be left empty, please enter something\n";
		std::getline(std::cin, name);
	}
	_contacts[index].setNickname(name);

	std::cout << "Phone number: ";
	std::getline(std::cin, name);
	while (name.empty())
	{
		std::cout << "No category can be left empty, please enter something\n";
		std::getline(std::cin, name);
	}
	_contacts[index].setNumber(name);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, name);
	while (name.empty())
	{
		std::cout << "No category can be left empty, please enter something\n";
		std::getline(std::cin, name);
	}
	_contacts[index].setSecret(name);
	this->index++;
}

// PRIVATE /////////////////////

void	PhoneBook::display_contact_list(void)
{
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "         " << i << "|";
		if (_contacts[i].getFname().empty())	
			std::cout << "          ";
		else
			_contacts->displayName(_contacts[i].getFname());
		std::cout << "|";
		if (_contacts[i].getLname().empty())	
			std::cout << "          ";
		else
			_contacts->displayName(_contacts[i].getLname());
		std::cout << "|";
		if (_contacts[i].getNickname().empty())	
			std::cout << "          ";
		else
			_contacts->displayName(_contacts[i].getNickname());
		std::cout << "|";
		std::cout << std::endl;
	}
	return;
}

void	PhoneBook::display_contact(int index)
{
	std::cout << "First name: " <<  _contacts[index].getFname() << std::endl;
	std::cout << "Last name: " <<  _contacts[index].getLname() << std::endl;
	std::cout << "Nickname: " <<  _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " <<  _contacts[index].getNumber() << std::endl;
	std::cout << "Darkest secret: " <<  _contacts[index].getSecret() << std::endl;
}

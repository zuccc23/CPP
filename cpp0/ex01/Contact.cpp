#include "Contact.class.hpp"
#include <iostream>
#include <string.h>

Contact::Contact(void)
{
	std::cout << "construct contact" << std::endl;
	setFname("         ");
	return;
}

Contact::~Contact(void)
{
	std::cout << "destruct contact" << std::endl;
	return;
}

std::string	Contact::getFname(void)
{
	return (this->first_name);
}

void	Contact::setFname(std::string name)
{
	this->first_name = name;
	if (this->first_name.length() > 10)
	{
		this->first_name.erase(10);
		this->first_name.replace(9, 1, 1, '.');
	}
	while (this->first_name.length() < 10)
	{
		this->first_name.insert(0, " ");
	}
	return;
}
#include "Contact.class.hpp"
#include <iostream>
#include <string.h>

// CONSTRUCTOR - DESTRUCTOR /////////////////////

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::displayName(std::string name)
{
	if (name.length() > 10)
	{
		name.erase(10);
		name.replace(9, 1, 1, '.');
	}
	while (name.length() < 10)
	{
		name.insert(0, " ");
	}
	std::cout << name ;
	return;
}

// SETTER - GETTER //////////////////////////

std::string	Contact::getFname(void)
{
	return (this->first_name);
}

void	Contact::setFname(std::string name)
{
	this->first_name = name;
	return;
}

std::string	Contact::getLname(void)
{
	return (this->last_name);
}

void	Contact::setLname(std::string name)
{
	this->last_name = name;
	return;
}

std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

void	Contact::setNickname(std::string name)
{
	this->nickname = name;
	return;
}

std::string	Contact::getNumber(void)
{
	return (this->number);
}

void	Contact::setNumber(std::string name)
{
	this->number = name;
	return;
}

std::string	Contact::getSecret(void)
{
	return (this->secret);
}

void	Contact::setSecret(std::string name)
{
	this->secret = name;
	return;
}
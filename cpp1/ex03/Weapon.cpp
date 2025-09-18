#include "Weapon.hpp"

// CONSTRUCTOR - DESTRUCTOR /////////////////////

Weapon::Weapon(std::string newType) : type(newType) {

	return;
}

Weapon::~Weapon(void)
{
	return;
}

// PUBLIC /////////////////////

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}
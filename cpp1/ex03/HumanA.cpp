#include "HumanA.hpp"

// CONSTRUCTOR - DESTRUCTOR /////////////////////

HumanA::HumanA(std::string	newName, Weapon& newWeapon) : name(newName), weapon(newWeapon){
	
	return;
}

HumanA::~HumanA(void)
{
	return;
}

// PUBLIC /////////////////////

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
#include "Zombie.hpp"

// CONSTRUCTOR - DESTRUCTOR /////////////////////

Zombie::Zombie(void)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroying " << name << std::endl;
	return;
}

// PUBLIC /////////////////////

void	Zombie::setName(std::string zombie_name)
{
	name = zombie_name;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
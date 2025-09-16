#include "Zombie.hpp"

// CONSTRUCTOR - DESTRUCTOR /////////////////////

Zombie::Zombie(std::string zombie_name)
{
	name = zombie_name;
	return;
}

Zombie::~Zombie(void)
{
	return;
}

// PUBLIC /////////////////////

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
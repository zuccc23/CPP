#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& to_copy);
		ScavTrap& operator=(const ScavTrap& to_copy);
		~ScavTrap();

		void guardGate();
	
};

#endif
#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap { 
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& to_copy);
		FragTrap& operator=(const FragTrap& to_copy);
		~FragTrap();

		void highFivesGuys(void);
		void attack(const std::string& target);

	private:
		/*content*/
	
};

#endif
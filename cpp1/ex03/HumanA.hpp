#ifndef HUMANA_HPP

# define HUMANA_HPP
# include <string.h>
# include <iostream>
# include <stdlib.h>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon& weapon;
		
	public:
		HumanA(std::string	newName, Weapon& newWeapon);
		~HumanA();

		void	attack();
};

#endif
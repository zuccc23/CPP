#ifndef HUMANB_HPP

# define HUMANB_HPP
# include <string.h>
# include <iostream>
# include <stdlib.h>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string	newName);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon weapon);

	private:
		std::string	name;
		Weapon* weapon;

};



#endif
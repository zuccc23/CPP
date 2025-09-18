#ifndef WEAPON_HPP

# define WEAPON_HPP
# include <string.h>
# include <iostream>
# include <stdlib.h>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string newType);
		~Weapon();

		const std::string&	getType(void);
		void				setType(std::string newType);
};


#endif
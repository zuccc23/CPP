#ifndef CLAP_TRAP_HPP

# define CLAP_TRAP_HPP
# include <string.h>
# include <iostream>
# include <stdlib.h>

class ClapTrap {
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& to_copy);
		ClapTrap& operator=(const ClapTrap& to_copy);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	
};

#endif
#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <iostream>
# include <stdlib.h>
# include <memory>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie(std::string zombie_name);
		~Zombie(void);
		void	announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
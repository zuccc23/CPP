#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <iostream>
# include <stdlib.h>
# include <memory>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie(void);
		~Zombie(void);

		void	setName(std::string zombie_name);
		void	announce(void);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
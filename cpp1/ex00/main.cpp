#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zomb = newZombie("joseph");

	randomChump("jotaro");
	zomb->announce();
	delete(zomb);
	return(0);
}

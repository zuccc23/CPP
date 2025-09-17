#include "Zombie.hpp"

int	main(void)
{
	int N = 6;
	Zombie	*zomb = zombieHorde(N, "joseph");

	for (int i = 0; i < N; i++)
		zomb[0].announce();
	
	delete[] (zomb);
	return(0);
}

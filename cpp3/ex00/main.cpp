#include "ClapTrap.hpp"
#include <string.h>
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	ClapTrap fighter1("Polnareff");
	ClapTrap fighter2("Jotaro");

	std::cout << "Polnareff attacks and takes damage 10+ times:" << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		fighter1.attack("Iggy");
		fighter1.takeDamage(2);
	}

	std::cout << "------------------" << std::endl;

	std::cout << "Jotaro gets repaired 10+ times:" << std::endl;
	for (int i = 0; i <= 10; i++)
		fighter2.beRepaired(1);
}
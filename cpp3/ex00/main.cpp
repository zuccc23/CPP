#include "ClapTrap.hpp"
#include <string.h>
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	// ClapTrap fighter1("Polnareff");
	// ClapTrap fighter2("Jotaro");
	// ClapTrap fighter3("Kakyoin");

	// std::cout << "Polnareff attacks and takes damage 10+ times:" << std::endl;
	// for (int i = 0; i <= 10; i++)
	// 	fighter1.attack("Iggy");

	// std::cout << "------------------" << std::endl;
	// std::cout << "Jotaro gets repaired 10+ times:" << std::endl;
	// for (int i = 0; i <= 10; i++)
	// 	fighter2.beRepaired(1);

	// std::cout << "------------------" << std::endl;
	// std::cout << "Kakyoin takes damage then tries to attack:" << std::endl;
	// fighter3.takeDamage(2);
	// fighter3.takeDamage(9);
	// fighter3.attack("Polnareff");

	std::cout << "===== EXERCISE 00: ClapTrap =====" << std::endl << std::endl;

	std::cout << "--- Creating a ClapTrap ---" << std::endl;
	ClapTrap clap("Clappy");
	std::cout << std::endl;

	std::cout << "--- Testing attack() ---" << std::endl;
	clap.attack("Dummy");
	std::cout << std::endl;

	std::cout << "--- Testing takeDamage() ---" << std::endl;
	clap.takeDamage(3);
	std::cout << std::endl;

	std::cout << "--- Testing beRepaired() ---" << std::endl;
	clap.beRepaired(2);
	std::cout << std::endl;

	std::cout << "--- Using up all energy points ---" << std::endl;
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	clap.attack("Enemy");
	std::cout << "--- Trying to attack with no energy ---" << std::endl;
	clap.attack("Enemy");
	std::cout << std::endl;

	std::cout << "--- Dealing damage until destruction ---" << std::endl;
	ClapTrap clap2("Weak");
	clap2.takeDamage(10);
	std::cout << "--- Trying to attack with no HP ---" << std::endl;
	clap2.attack("Target");
	std::cout << std::endl;

	std::cout << "--- Destroying ClapTrap ---" << std::endl;
	return (0);

}
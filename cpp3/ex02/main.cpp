#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string.h>
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	// FragTrap fighter1("Polnareff");
	// FragTrap fighter2("Jotaro");
	// FragTrap fighter3("Kakyoin");
	// // ScavTrap fighter4;
	// // fighter4.attack("idk");

	// std::cout << "------------------" << std::endl;
	// std::cout << "Polnareff attacks and takes damage 50+ times:" << std::endl;
	// for (int i = 0; i <= 50; i++)
	// 	fighter1.attack("Iggy");

	// // std::cout << "------------------" << std::endl;
	// // std::cout << "Jotaro gets repaired 10+ times:" << std::endl;
	// // for (int i = 0; i <= 10; i++)
	// // 	fighter2.beRepaired(1);

	// std::cout << "------------------" << std::endl;
	// std::cout << "Kakyoin takes damage then tries to attack:" << std::endl;
	// fighter3.takeDamage(20);
	// fighter3.takeDamage(90);
	// fighter3.attack("Polnareff");
	// std::cout << "------------------" << std::endl;
	// fighter1.guardGate();
	// fighter2.highFivesGuys();
	// std::cout << "------------------" << std::endl;
	/////////////////////////////////////////////////////////////////////////

	std::cout << "===== EXERCISE 02: FragTrap =====" << std::endl << std::endl;

	std::cout << "--- Creating a ClapTrap ---" << std::endl;
	ClapTrap clap("BasicClap");
	std::cout << std::endl;

	std::cout << "--- Creating a ScavTrap ---" << std::endl;
	ScavTrap scav("Scavy");
	std::cout << std::endl;

	std::cout << "--- Creating a FragTrap (shows construction chain) ---" << std::endl;
	FragTrap frag("Fraggy");
	std::cout << std::endl;

	std::cout << "--- Testing FragTrap attack() ---" << std::endl;
	frag.attack("Target");
	std::cout << std::endl;

	std::cout << "--- Testing FragTrap takeDamage() ---" << std::endl;
	frag.takeDamage(30);
	std::cout << std::endl;

	std::cout << "--- Testing FragTrap beRepaired() ---" << std::endl;
	frag.beRepaired(25);
	std::cout << std::endl;

	std::cout << "--- Testing FragTrap special ability: highFivesGuys() ---" << std::endl;
	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "--- Using energy until depleted ---" << std::endl;
	for (int i = 0; i < 100; i++)
		frag.attack("Dummy");
	std::cout << "--- Trying to use highFivesGuys() with no energy ---" << std::endl;
	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "--- Comparing FragTrap vs ScavTrap attributes ---" << std::endl;
	FragTrap frag2("Strong");
	ScavTrap scav2("Weaker");
	std::cout << "FragTrap has higher HP, energy, and attack than ScavTrap" << std::endl;
	frag2.attack("Enemy");
	scav2.attack("Enemy");
	std::cout << std::endl;

	std::cout << "--- Testing multiple instances ---" << std::endl;
	FragTrap frag3("Another");
	frag3.highFivesGuys();
	std::cout << std::endl;

	std::cout << "--- Destroying all objects (construction/destruction chain) ---" << std::endl;
}
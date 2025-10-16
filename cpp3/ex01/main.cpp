#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string.h>
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	// ScavTrap fighter1("Polnareff");
	// ScavTrap fighter2("Jotaro");
	// ScavTrap fighter3("Kakyoin");

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
	// std::cout << "------------------" << std::endl;

	std::cout << "===== EXERCISE 01: ScavTrap =====" << std::endl << std::endl;

	std::cout << "--- Creating a ClapTrap ---" << std::endl;
	ClapTrap clap("BasicClap");
	std::cout << std::endl;

	std::cout << "--- Creating a ScavTrap (shows construction chain) ---" << std::endl;
	ScavTrap scav("Scavy");
	std::cout << std::endl;

	std::cout << "--- Testing ScavTrap attack() (different message) ---" << std::endl;
	scav.attack("Target");
	std::cout << std::endl;

	std::cout << "--- Testing ScavTrap takeDamage() ---" << std::endl;
	scav.takeDamage(20);
	std::cout << std::endl;

	std::cout << "--- Testing ScavTrap beRepaired() ---" << std::endl;
	scav.beRepaired(15);
	std::cout << std::endl;

	std::cout << "--- Testing ScavTrap special ability: guardGate() ---" << std::endl;
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "--- Using energy until depleted ---" << std::endl;
	for (int i = 0; i < 50; i++)
		scav.attack("Dummy");
	std::cout << "--- Trying to use guardGate() with no energy ---" << std::endl;
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "--- Testing high damage ---" << std::endl;
	ScavTrap scav2("Tough");
	scav2.takeDamage(100);
	std::cout << std::endl;

	std::cout << "--- Destroying objects (destruction chain) ---" << std::endl;
	return (0);

}
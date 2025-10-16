#include "ScavTrap.hpp"

//CONSTRUCTOR
ScavTrap::ScavTrap() : ClapTrap() {
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	
	std::cout << "ScavTrap " << _name << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called." << std::endl;
}

//COPY CONSTRUCTOR
ScavTrap::ScavTrap(const ScavTrap& to_copy) : ClapTrap(to_copy) {
	std::cout << "ScavTrap " << _name << " copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
ScavTrap& ScavTrap::operator=(const ScavTrap& to_copy) {
	if (this != &to_copy)
		ClapTrap::operator=(to_copy);
	std::cout << "ScavTrap copy assignment called." << std::endl;
	return *this;
}

//DESTRUCTOR
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called." << std::endl;
}

//PUBLIC
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in keeper mode." << std::endl;
}

//PRIVATE

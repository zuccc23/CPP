#include "FragTrap.hpp"

//CONSTRUCTOR
FragTrap::FragTrap() :ClapTrap() {
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	
	std::cout << "FragTrap " << _name << " constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor called." << std::endl;
}

// COPY CONSTRUCTOR
FragTrap::FragTrap(const FragTrap& to_copy) : ClapTrap(to_copy) {
	std::cout << "FragTrap " << _name << " copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
FragTrap& FragTrap::operator=(const FragTrap& to_copy){
	if (this != &to_copy)
		FragTrap::operator=(to_copy);
	std::cout << "FragTrap copy assignment called." << std::endl;
	return *this;
}

//DESTRUCTOR
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called." << std::endl;
}

//PUBLIC
void FragTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " does not have enough energy or hit points to attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " is too tired to high five..." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " wants to high five!!!!" << std::endl;
}

//PRIVATE

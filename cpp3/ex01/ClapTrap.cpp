#include "ClapTrap.hpp"

//CONSTRUCTOR
ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0){
	_name = "default";
	std::cout << "ClapTrap " << _name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap " << _name << " constructor called." << std::endl;
}

//COPY CONSTRUCTOR
ClapTrap::ClapTrap(const ClapTrap& to_copy) {
	std::cout << "Copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
ClapTrap& ClapTrap::operator=(const ClapTrap& to_copy) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &to_copy)
	{
		_name = to_copy._name;
		_hitPoints = to_copy._hitPoints;
		_attackDamage = to_copy._attackDamage;
		_energyPoints = to_copy._energyPoints;
	}
	return (*this);
}

//DESTRUCTOR
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called." << std::endl;
}

//PUBLIC
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " does not have enough energy or hit points to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of attack damage." << " It now has " << _hitPoints << " hit points." << std::endl;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " does not have enough energy or hit points to repair itself!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " regained " << amount << " hit points." << " It now has " << _hitPoints << " hit points." << std::endl;
	_energyPoints--;
}


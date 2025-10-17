#include "WrongAnimal.hpp"

//CONSTRUCTOR
WrongAnimal::WrongAnimal() : _type("Wronganimal") {
	std::cout << "Wrong Animal constructor called." << std::endl;
}

//COPY CONSTRUCTOR
WrongAnimal::WrongAnimal(const WrongAnimal& to_copy) {
	std::cout << "Wrong Animal copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& to_copy) {
	std::cout << "Wrong Animal copy assignment operator called." << std::endl;
	if (this != &to_copy)
		_type = to_copy._type;
	return (*this);
}

//DESTRUCTOR
WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal destructor called."<< std::endl;
}

//PUBLIC

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Some Wrong animal made a sound."<< std::endl;
}

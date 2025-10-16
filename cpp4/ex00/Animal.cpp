#include "Animal.hpp"

//CONSTRUCTOR
Animal::Animal() : _type("unknown") {
	std::cout << "Animal constructor called." << std::endl;
}

//COPY CONSTRUCTOR
Animal::Animal(const Animal& to_copy) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
Animal& Animal::operator=(const Animal& to_copy) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &to_copy)
		_type = to_copy._type;
	return (*this);
}

//DESTRUCTOR
Animal::~Animal() {
	std::cout << "Animal destructor called."<< std::endl;
}

//PUBLIC

std::string	Animal::getType(void)
{
	return (_type);
}

void	Animal::setType(Animal animal)
{
	_type = animal.getType();
}

//PRIVATE

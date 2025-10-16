#include "Dog.hpp"

//CONSTRUCTOR
Dog::Dog() : Animal() {
	std::cout << "Dog constructor called." << std::endl;
}

//COPY CONSTRUCTOR
Dog::Dog(const Dog& to_copy) : Animal(to_copy) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
Dog& Dog::operator=(const Dog& to_copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &to_copy)
		Animal::operator=(to_copy);
	return (*this);
}

//DESTRUCTOR
Dog::~Dog() {
	std::cout << "Dog destructor called."<< std::endl;
}

//PUBLIC

//PRIVATE

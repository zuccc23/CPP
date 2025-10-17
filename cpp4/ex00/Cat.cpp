#include "Cat.hpp"

//CONSTRUCTOR
Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

//COPY CONSTRUCTOR
Cat::Cat(const Cat& to_copy) : Animal(to_copy) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
Cat& Cat::operator=(const Cat& to_copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &to_copy)
		Animal::operator=(to_copy);
	return (*this);
}

//DESTRUCTOR
Cat::~Cat() {
	std::cout << "Cat destructor called."<< std::endl;
}

//PUBLIC
void	Cat::makeSound(void) const
{
	std::cout << "mmeeooowwwww!!!!"<< std::endl;
}

//PRIVATE

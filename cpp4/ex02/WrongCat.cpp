#include "WrongCat.hpp"

//CONSTRUCTOR
WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << "WrongCat constructor called." << std::endl;
}

//COPY CONSTRUCTOR
WrongCat::WrongCat(const WrongCat& to_copy) : WrongAnimal(to_copy) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
WrongCat& WrongCat::operator=(const WrongCat& to_copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &to_copy)
		WrongAnimal::operator=(to_copy);
	return (*this);
}

//DESTRUCTOR
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called."<< std::endl;
}

//PUBLIC
void	WrongCat::makeSound(void) const
{
	std::cout << "mwmwmwowmwmwoawwowm!!!! (thats a wrong cat)"<< std::endl;
}
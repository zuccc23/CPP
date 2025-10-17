#include "Dog.hpp"

//CONSTRUCTOR
Dog::Dog(){
	_type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
	_brain = new Brain;
}

//COPY CONSTRUCTOR
Dog::Dog(const Dog& to_copy) : Animal(to_copy) {
	std::cout << "Dog copy constructor called." << std::endl;
	_brain = new Brain(*to_copy._brain);
}

//COPY ASSIGNMENT
Dog& Dog::operator=(const Dog& to_copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &to_copy)
	{
		Animal::operator=(to_copy);
		delete _brain;
		_brain = new Brain(*to_copy._brain);
	}
	return (*this);
}

//DESTRUCTOR
Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called."<< std::endl;
}

//PUBLIC
void	Dog::makeSound() const
{
	std::cout << "Woof!!!"<< std::endl;
}

void	Dog::setIdea(std::string idea, int index)
{
	_brain->setIdea(idea,index);
}
std::string	Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}

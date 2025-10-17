#include "Cat.hpp"

//CONSTRUCTOR
Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
	_brain = new Brain;
}

//COPY CONSTRUCTOR
Cat::Cat(const Cat& to_copy) : Animal(to_copy) {
	std::cout << "Cat copy constructor called." << std::endl;
	_brain = new Brain(*to_copy._brain);
}

//COPY ASSIGNMENT
Cat& Cat::operator=(const Cat& to_copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &to_copy)
	{
		Animal::operator=(to_copy);
		delete _brain;
		_brain = new Brain(*to_copy._brain);
	}
	return (*this);
}

//DESTRUCTOR
Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called."<< std::endl;
}

//PUBLIC
void	Cat::makeSound(void) const
{
	std::cout << "mmeeooowwwww!!!!"<< std::endl;
}

void	Cat::setIdea(std::string idea, int index)
{
	_brain->setIdea(idea,index);
}
std::string	Cat::getIdea(int index) const
{
	return (_brain->getIdea(index));
}

//PRIVATE

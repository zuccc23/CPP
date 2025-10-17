#include "Brain.hpp"

//CONSTRUCTOR
Brain::Brain() {
	std::cout << "Brain constructor called." << std::endl;
}

//COPY CONSTRUCTOR
Brain::Brain(const Brain& to_copy) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
    	_ideas[i] = to_copy._ideas[i];
}

//COPY ASSIGNMENT
Brain& Brain::operator=(const Brain& to_copy) {
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this != &to_copy)
	{
		for (int i = 0; i < 100; i++)
    		_ideas[i] = to_copy._ideas[i];
	}
	return (*this);
}

//DESTRUCTOR
Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

//PUBLIC
void	Brain::setIdea(std::string idea, int index)
{
	_ideas[index] = idea;
}
std::string	Brain::getIdea(int index) const
{
	return (_ideas[index]);
}



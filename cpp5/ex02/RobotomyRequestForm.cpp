#include "RobotomyRequestForm.hpp"
#include <cstdlib> 
#include <ctime>

//CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm()  : AForm("Robotomy Creation Form", 72, 45), _target("default") {
	std::cout << "\033[90mRobotomyRequestForm constructor called.\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)  : AForm("Robotomy Creation Form", 72, 45), _target(target) {
	std::cout << "\033[90mRobotomyRequestForm constructor called.\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& to_copy) : AForm(to_copy), _target(to_copy._target)  {
	std::cout << "\033[90mRobotomyRequestForm copy constructor called.\033[0m" << std::endl;
}

//COPY ASSIGNMENT
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& to_copy) {
	std::cout << "\033[90mRobotomyRequestForm copy assignment operator called.\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_target = to_copy._target;
	}
	return (*this);
}

//DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\033[90mRobotomyRequestForm destructor called.\033[0m" << std::endl;
}

//PUBLIC
void RobotomyRequestForm::executeAction() const
{
	srand(time(0));
	int test = rand() % 100;
	std::cout << "Drrrr... Tttszzz...\n";
	if (test % 2 == 0)
		std::cout << _target << "'s robotomy was successful !\n";
	else
		std::cout << _target << "'s robotomy has failed...\n";
}

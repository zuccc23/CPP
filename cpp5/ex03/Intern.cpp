#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//CONSTRUCTOR
Intern::Intern() {
	std::cout << "\033[90m✿Intern constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
Intern::Intern(const Intern& to_copy) {
	std::cout << "\033[90m✿Intern copy constructor called✿\033[0m" << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
Intern& Intern::operator=(const Intern& to_copy) {
	(void)to_copy;
	std::cout << "\033[90m✿Intern copy assignment operator called✿\033[0m" << std::endl;
	return (*this);
}

//DESTRUCTOR
Intern::~Intern() {
	std::cout << "\033[90m~Intern destructor called\033[0m" << std::endl;
}

//PUBLIC
AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	list[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (*formCreators[])(const std::string&) = {
        &createShrubbery,
		&createRobotomy,
		&createPresidential
    };

	for (int i = 0; i < 3; i++)
	{
		if (formName == list[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formCreators[i](formTarget));
		}
	}
	std::cout << "Error: " << formName << " does not exist" << std::endl;
	return (NULL);
}

//NON MEMBER
AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

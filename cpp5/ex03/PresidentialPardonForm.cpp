#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default") {
	
	std::cout << "\033[90m✿PresidentialPardonForm constructor called✿\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
	
	std::cout << "\033[90m✿PresidentialPardonForm constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& to_copy) : AForm(to_copy), _target(to_copy._target) {
	std::cout << "\033[90m✿PresidentialPardonForm copy constructor called✿\033[0m" << std::endl;
}

//COPY ASSIGNMENT
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& to_copy) {
	std::cout << "\033[90m✿PresidentialPardonForm copy assignment operator called✿\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_target = to_copy._target;
	}
	return (*this);
}

//DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\033[90m~PresidentialPardonForm destructor called.\033[0m" << std::endl;
}

//PUBLIC
void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
